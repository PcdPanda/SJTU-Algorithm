class Creature
{
	private:
		int stamina,strengthen,precision;
};
class Material
{
	public:
		Material();
		~Material();
};
class Potion:public Material
{
};
class Die:public Material
{
	public:
		int roll(){return rand()%100+1;}
};
class Weapon:public Material
{
};
class Room
{
	public:
		Room();
		~Room();
	private
		Material *m[5];
		Creature *c[2];
};
class Prince:public Creature
{
	public:
		Prince(sta,str,pre,sil)
		{
			stamina=sta;strengthen=str;precision=pre;silence=sil;
			knife=0;sword=0;potion=0;
		}
		void Fight();
		void Escape();
		void drink()
		{
			if(potion==0)a<<"There is no potion any more";
			else 
			{
				potion--;stamina+=5;
			}
		}
		void die();
	private:
		int silence,knife,sword,potion;	
};
class Princess:public Creature
{
};
class Monster:public Creature
{
};
class Castle
{
	public:
		Castle(){for(int i=0;i<=3;i++)r[i]=new Room;}
		~Caslte(){for(int i=0;i<=3;i++)delete r[i];}
	private:
		Room*r[4];
};
