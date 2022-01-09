#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cassert>
#include "world_type.h"
int read_program(ifstream& species,world_t &world);//read the species' programs

int read_world(ifstream& worldfile,world_t &world);//read the world file

int read_file(char summary_file[],char world_file[],world_t &world);//read all the files

void instruct(creature_t &creatures,grid_t &grid,int v);
void Hop(creature_t&creatures,grid_t&grid,int v);

void Left(creature_t&creatures,int v);

void Right(creature_t&creatures,grid_t&grid,int v);

void Infect(creature_t&creatures,int v);

void Ifempty(creature_t&creatures,grid_t&grid,int add,int v);

void Ifenemy(creature_t&creatures,grid_t&grid,int add,int v);

void Ifsame(creature_t&creatures,grid_t&grid,int add,int v);

void Ifwall(creature_t&creatures,grid_t&grid,int add,int v);

void Go(creature_t&creatures,grid_t&grid,int add,int v);

void printgrid(grid_t &grid);



void day(world_t&world,int v);


#endif
