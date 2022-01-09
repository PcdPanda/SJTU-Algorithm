#include "simulation.h"
using namespace std;
int read_file(char summary_file[],char world_file[],world_t &world)
{
	ifstream species,worldfile;
	species.open(summary_file);
	if(species){
		if(read_program(species,world));
		else return 0;
	}
	else {
		cout<<"Error: Cannot open file "<<summary_file<<"!"; 
		return 0;
	}	
	species.close();
	worldfile.open(world_file);
	if(worldfile){
		if(read_world(worldfile,world));
		else return 0;
	}
	else 
	{
		cout<<"Error: Cannot open file "<<world_file<<"!"; 
		return 0;
	}			
	worldfile.close();
	return 1;
}

int read_program(ifstream& species,world_t &world)//species initializer
{
	string dir,name[MAXSPECIES],spe_dir[MAXSPECIES],str,str1,str2;//name of species
	ifstream program;//the files containing programs
	int i=0,j=0,k=0,l=0,add=0;//variables for counting
	getline(species,dir);//read the directory
	//read the species file and find the directory
	while(getline(species,name[i]))
	{
		if(i>=MAXSPECIES){
			cout<<"Error: Too many species!"<<endl<<"Maximal number of species is "<<MAXSPECIES<<"."<<endl;
			return 0;
		}
		world.species[i].name=name[i];//give the species their names
		spe_dir[i]=dir;//read the directory
		spe_dir[i].append("/");
		spe_dir[i].append(name[i]);//construct the directory path
		i++;
	}
	world.numSpecies=i;
	//j represents for the current species for reading
	for(j=0;j<i;j++)					
	{
		program.open(spe_dir[j].c_str());
		if(program){					
			//read the species files and programs successfully		
			l=0;//l represents for the number of programs under reading							
			while(getline(program,str)){
				if(str.length()==0)break;//all programs have been read
				if(l>=MAXPROGRAM){
					cout<<"Error: Too many instructions for species "<<name[j]<<"!"<<endl;
					cout<<"Maximal number of instructions is "<<MAXPROGRAM<<"."<<endl;
					return 0;
				}
				else{
					k=str.find(' ',0);					//read the first words in str1
					str1=str.substr(0,k);
				}
				//determine the programs

					if(str1==opName[0])world.species[j].program[l].op=HOP;
					else if(str1==opName[1])world.species[j].program[l].op=LEFT;
					else if(str1==opName[2])world.species[j].program[l].op=RIGHT;
					else if(str1==opName[3])world.species[j].program[l].op=INFECT;
					else {
						str2=str.substr(k+1,str.find(' ',k+1)-k-1);		//read the addressin str2
						add=atoi(str2.c_str());							//convert string str2 to int add
						if(str1==opName[4]){
							world.species[j].program[l].op=IFEMPTY;
							world.species[j].program[l].address=add;							
						}
						else if(str1==opName[5]){
							world.species[j].program[l].op=IFENEMY;
							world.species[j].program[l].address=add;							
						}
						else if(str1==opName[6]){
							world.species[j].program[l].op=IFSAME;
							world.species[j].program[l].address=add;							
						}
						else if(str1==opName[7]){
							world.species[j].program[l].op=IFWALL;
							world.species[j].program[l].address=add;							
						}
						else if(str1==opName[8]){
							world.species[j].program[l].op=GO;
							world.species[j].program[l].address=add;							
						}
						else {
							cout<<"Error: Instruction "<<str1<<" is not recognized!"<<endl;
							return 0;
						}
					}
					world.species[j].programSize=l;	
					l++;						
				}
			}
			else{
				cout<<"Error: Cannot open file "<<name[j]<<"!"; 
				return 0;
			}
		program.close();
	}
	return 1;	
}

int read_world(ifstream& worldfile,world_t &world)//world initializer
{
	string str,str1,spe,id,ir,ic,a1,a2;//Temporary string variable for reading from files
	int i,j,k,Row,Column;//Temporary int variables for counting  
	//read the height of the grid
	if(getline(worldfile,str)){								
		world.grid.height=atoi(str.c_str());
		if(world.grid.height<1||world.grid.height>MAXHEIGHT){
			cout<<"Error: The grid height is illegal!";
			return 0;
		}
	} 
	else return 0;
	//read the width of the grid
	if(getline(worldfile,str)){								
		world.grid.width=atoi(str.c_str());
		if(world.grid.width<1||world.grid.width>MAXWIDTH){
			cout<<"Error: The grid width is illegal!";
			return 0;
		}
	} 
	else return 0;
	//read the terrain layout
	for(i=0;i<world.grid.height;i++){							
		for(j=0;j<world.grid.width;j++){
			str=worldfile.get();	
			world.grid.squares[i][j]=NULL; 				//generate the terrain
			if(str==terrainShortName[0])world.grid.terrain[i][j]=PLAIN;
			else if (str==terrainShortName[1])world.grid.terrain[i][j]=LAKE;
			else if (str==terrainShortName[2])world.grid.terrain[i][j]=FOREST;
			else if (str==terrainShortName[3])world.grid.terrain[i][j]=HILL;
			else{
				cout<<"Error: Terrain square ("<<str<<" "<<i<<" "<<j<<") is invalid!";
				return 0;
			}
		}
		worldfile.get();
	}
	
	i=0;										//read the creatures files
	while(getline(worldfile,str)){
		a1="";a2="";
		if(i>=MAXCREATURES){
			cout<<"Error: Too many creatures!"<<endl;
			cout<<"Maximal number of creatures is "<<MAXCREATURES<<".";
			return 0;
		}
		world.creatures[i].programID=0;						//generate the creature
		//read information of every creatures from the world files
		for(j=1;j<=6;j++)
		{	
			if(j==1){
				k=str.find(' ',0);
				str1=str.substr(0,k);
			}
			else{
				str1=str.substr(k+1,str.find(' ',k+1)-k-1);
				k=str.find(' ',k+1);
			}
			switch (j){
				case 1:spe=str1;break;//get the species
				case 2:id=str1;break;//get the initial direction
				case 3:ir=str1;break;//get the initial row
				case 4:ic=str1;break;//get the inital cloumn
				case 5:a1=str1;break;//get the first ability
				case 6:a2=str1;break;//get the first ability
			}			
			if(a2==a1&&a1!=""){
				j--;
				continue;
			}
			if(k==-1)break;	
		}
		//determine the initial direction
		if(id==directName[0])world.creatures[i].direction=EAST;					
		else if(id==directName[1])world.creatures[i].direction=SOUTH;
		else if(id==directName[2])world.creatures[i].direction=WEST;
		else if(id==directName[3])world.creatures[i].direction=NORTH;
		else{
			cout<<"Error: Direction "<<id<<" is not recognized!"<<endl;
			return 0;
		}
		//determine the initial location 
		Row=atoi(ir.c_str());
		Column=atoi(ic.c_str());
		if(Row>=world.grid.height||Row<0||Column>=world.grid.width||Column<0){
			cout<<"Error: Creature ("<<spe<<" "<<id<<" "<<ir<<" "<<ic<<") is out of bound!"<<endl;
			cout<<"The grid size is "<<world.grid.height<<"-by-"<<world.grid.width<<"."<<endl;
			return 0; 
		} 
		world.creatures[i].location.r=Row;
		world.creatures[i].location.c=Column;
		//determine the initial species
		k=0;
		for(j=0;j<world.numSpecies;j++){
			if(spe==world.species[j].name)
			{
				world.creatures[i].species=&world.species[j];	
				k=1;
			}
		}
		if(k==0){
			cout<<"Error: Species "<<spe<<" not found!"<<endl;	
			return 0;
		}
		//determine the abilities
		if(a1!="a"&&a1!="f"&&a1!=""){
			cout<<"Error: Creature ("<<spe<<" "<<id<<" "<<ir<<" "<<ic<<") has an invalid ability "<<a1<<endl;
			return 0;	
		}
		else if(a2!="a"&&a2!="f"&&a2!=""){
			cout<<"Error: Creature ("<<spe<<" "<<id<<" "<<ir<<" "<<ic<<") has an invalid ability "<<a2<<endl;
			return 0;	
		}
		if(a1=="a"||a2=="a")world.creatures[i].ability[ARCH]=true;
		else world.creatures[i].ability[ARCH]=false;
		if(a1=="f"||a2=="f")world.creatures[i].ability[FLY]=true;
		else world.creatures[i].ability[FLY]=false;
		//determine whether hillactive
		if(world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL&&world.creatures[i].ability[FLY]==0)world.creatures[i].hillActive=1;
		else world.creatures[i].hillActive=0;
		//check whether overlap
		for(j=0;j<i;j++){
			if(world.creatures[j].location.r==world.creatures[i].location.r&&world.creatures[j].location.c==world.creatures[i].location.c){
				cout<<"Error: Creature ("<<spe<<" "<<id<<" "<<ir<<" "<<ic<<") overlaps with creature (";
				cout<<world.creatures[j].species->name<<" ";
				switch(world.creatures[j].direction){
					case 0:cout<<directName[0]<<" ";break;
					case 1:cout<<directName[1]<<" ";break;
					case 2:cout<<directName[2]<<" ";break;	
					case 3:cout<<directName[3]<<" ";break;					
				}
				cout<<world.creatures[j].location.r<<" ";		
				cout<<world.creatures[j].location.c<<")!"<<endl;	
				return 0;				
			}
		}
		world.grid.squares[world.creatures[i].location.r][world.creatures[i].location.c]=&world.creatures[i];
		if(world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==LAKE&&world.creatures[i].ability[FLY]==0){
			cout<<"Error: Creature ("<<spe<<" "<<id<<" "<<ir<<" "<<ic<<") is in a lake square!"<<endl;
			cout<<"The creature cannot fly!"<<endl;
			return 0;
		}
		i++;
	}
	world.numCreatures=i;
	return 1;
}
void Hop(creature_t&creatures,grid_t &grid,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	cout<<"hop"<<endl;
	switch (creatures.direction){
		case 0:c++;break;
		case 1:r++;break;
		case 2:c--;break;
		case 3:r--;break;		
	}
	creatures.programID++;
	if(creatures.ability[FLY]==0&&grid.terrain[r][c]==LAKE)return;
	if(c<0||r<0||r>=grid.height||c>=grid.width)return;
	if(grid.squares[r][c]!=NULL)return;
	grid.squares[r][c]=&creatures;
	grid.squares[creatures.location.r][creatures.location.c]=NULL;
	creatures.location.r=r;
	creatures.location.c=c;
}
void Left(creature_t&creatures,int v)
{
	cout<<"left"<<endl;
		switch (creatures.direction){
		case 0:creatures.direction=NORTH;break;
		case 1:creatures.direction=EAST;break;
		case 2:creatures.direction=SOUTH;break;
		case 3:creatures.direction=WEST;break;		
	}
	creatures.programID++;
}
void Right(creature_t&creatures,int v)
{
	cout<<"right"<<endl;
		switch (creatures.direction){
		case 0:creatures.direction=SOUTH;break;
		case 1:creatures.direction=WEST;break;
		case 2:creatures.direction=NORTH;break;
		case 3:creatures.direction=EAST;break;		
	}
	creatures.programID++;
}
void Infect(creature_t&creatures,grid_t&grid,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	cout<<"infect"<<endl;
	creatures.programID++;
	if(creatures.ability[ARCH]==true){
		while(1){
			switch (creatures.direction){
				case 0:c++;break;
				case 1:r++;break;
				case 2:c--;break;
				case 3:r--;break;		
			}	
			if(c<0||r<0||r>=grid.height||c>=grid.width)return;
			if(grid.squares[r][c]!=NULL&&grid.squares[r][c]->species->name!=creatures.species->name){
				grid.squares[r][c]->species=creatures.species;
				grid.squares[r][c]->programID=0; 
				break;
			}
		}
	}
	else{
		switch (creatures.direction){
			case 0:c++;break;
			case 1:r++;break;
			case 2:c--;break;
			case 3:r--;break;		
		}
		if(grid.squares[r][c]==NULL||c<0||r<0||r>=grid.height||c>=grid.width)return;
		if(grid.squares[r][c]!=NULL&&grid.squares[r][c]->species->name==creatures.species->name)return;
		if(grid.terrain[r][c]==FOREST)return;		
		if(grid.squares[r][c]!=NULL&&grid.squares[r][c]->species->name!=creatures.species->name){
			grid.squares[r][c]->species=creatures.species;
			grid.squares[r][c]->programID=0;
		}
	}
}
void Ifempty(creature_t&creatures,grid_t&grid,int add,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	if(v==1)cout<<"ifempty "<<add;
	switch (creatures.direction){
	case 0:c++;break;
	case 1:r++;break;
	case 2:c--;break;
	case 3:r--;break;		
	}
	if(c>=0&&r>=0&&c<grid.width&&r<grid.height&&grid.squares[r][c]==NULL&&grid.terrain[r][c]!=FOREST)creatures.programID=add-2;
	creatures.programID++;
	instruct(creatures,grid,v);
}
void Ifenemy(creature_t&creatures,grid_t&grid,int add,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	if(v==1)cout<<"ifenemy "<<add;
	switch (creatures.direction){
	case 0:c++;break;
	case 1:r++;break;
	case 2:c--;break;
	case 3:r--;break;		
	}
	if(c>=0&&r>=0&&c<grid.width&&r<grid.height){
		if(grid.terrain[r][c]!=FOREST&&grid.squares[r][c]!=NULL&&grid.squares[r][c]->species->name!=creatures.species->name)creatures.programID=add-2;
	}
	creatures.programID++;
	instruct(creatures,grid,v);
}

void Ifsame(creature_t&creatures,grid_t&grid,int add,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	if(v==1)cout<<"ifsame "<<add;
	switch (creatures.direction){
	case 0:c++;break;
	case 1:r++;break;
	case 2:c--;break;
	case 3:r--;break;		
	}
	if(c>=0&&r>=0&&c<grid.width&&r<grid.height){
		if(grid.terrain[r][c]!=FOREST&&grid.squares[r][c]!=NULL&&grid.squares[r][c]->species->name==creatures.species->name)creatures.programID=add-2;
	}
	creatures.programID++;
	instruct(creatures,grid,v);
}
void Ifwall(creature_t&creatures,grid_t&grid,int add,int v)
{
	int r=creatures.location.r,c=creatures.location.c;
	if(v==1)cout<<"ifwall "<<add;
	switch (creatures.direction){
	case 0:c++;break;
	case 1:r++;break;
	case 2:c--;break;
	case 3:r--;break;		
	}
	if(grid.terrain[r][c]==LAKE&&creatures.ability[FLY]==false)creatures.programID=add-2;
	else if(r<0||c<0||r>=grid.height||c>=grid.width)creatures.programID=add-2;
	creatures.programID++;
	instruct(creatures,grid,v);
}
void Go(creature_t&creatures,grid_t&grid,int add,int v)
{
	if(v==1)cout<<"go "<<add;
	creatures.programID=add-1;
	instruct(creatures,grid,v);	
}

void printgrid(grid_t &grid)						//print the grid
{
	int i=0,j=0;
	string str;
	for(j=0;j<grid.height;j++){
		for(i=0;i<grid.width;i++){
			if(grid.squares[j][i]==NULL)cout<<"____";
			else {
				str.assign(grid.squares[j][i]->species->name,0,2);
				cout<<str<<"_";
				switch (grid.squares[j][i]->direction){
					case 0:cout<<directShortName[0];break;
					case 1:cout<<directShortName[1];break;
					case 2:cout<<directShortName[2];break;
					case 3:cout<<directShortName[3];break; 
				}
			}

			cout<<" ";
		}
		cout<<endl;
	}
}
void instruct(creature_t &creatures,grid_t &grid,int v){
	if(v==1)cout<<endl<<"Instruction "<<creatures.programID+1<<": ";
	switch (creatures.species->program[creatures.programID].op){
		case 0:Hop(creatures,grid,v);break;
		case 1:Left(creatures,v);break;
		case 2:Right(creatures,v);break;
		case 3:Infect(creatures,grid,v);break;
		case 4:Ifempty(creatures,grid,creatures.species->program[creatures.programID].address,v);break;
		case 5:Ifenemy(creatures,grid,creatures.species->program[creatures.programID].address,v);break;
		case 6:Ifsame(creatures,grid,creatures.species->program[creatures.programID].address,v);break;
		case 7:Ifwall(creatures,grid,creatures.species->program[creatures.programID].address,v);break;
		case 8:Go(creatures,grid,creatures.species->program[creatures.programID].address,v);break;		
	}	
}

void day(world_t&world,int v){
	int i;
	for(i=0;i<world.numCreatures;i++){
		if(world.creatures[i].hillActive==1){
			world.creatures[i].hillActive=0;									//go to hill
			continue;
		}
		cout<<"Creature ("<<world.creatures[i].species->name<<" ";
		switch (world.creatures[i].direction){
			case 0:cout<<directName[0]<<" ";break;
			case 1:cout<<directName[1]<<" ";break;
			case 2:cout<<directName[2]<<" ";break;
			case 3:cout<<directName[3]<<" ";break;								
		}
		cout<<world.creatures[i].location.r<<" "<<world.creatures[i].location.c<<") takes action:";
		if(v==0)cout<<" "; 
		instruct(world.creatures[i],world.grid,v);
		if(v==1)printgrid(world.grid);	
		if(world.grid.terrain[world.creatures[i].location.r][world.creatures[i].location.c]==HILL&&world.creatures[i].hillActive!=1&&world.creatures[i].ability[FLY]==0)world.creatures[i].hillActive=1;
		else world.creatures[i].hillActive=0;
	}
	if(v==0)printgrid(world.grid);
}


