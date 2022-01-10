#include "assignment.h"
#include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void print(uset *set)
{
	for(int i=0;i<set->card;i++)
	{
		switch (set->type)
		{ 
			case CHAR:printf("%c ",*((char*)set->elem+i));break;
			case INT:printf("%d ",*((int*)set->elem+i));break;
			case DOUBLE:printf("%g ",*((double*)set->elem+i));break;
		}
	}	
}
void newSet(uset *set, int type)
{
	set->elem=malloc(INITSETSIZE*type);
	set->card=0;
	set->type=type;
}
void deletSet(uset *set)
{
	free(set->elem);
	set->elem=NULL;
}
void addElem(void *elem,uset*set)
{
	void*p;
	int i=0;
	if(set->elem==NULL)
	{
		printf("Add error,the Set has been deleted");exit(-1);
	} 
	for(i=0;i<set->card;i++)
	{
		if(*(char*)elem==*(char*)(set->elem+i*set->type)&&set->type==CHAR)return;
		if(*(int*)elem==*(int*)(set->elem+i*set->type)&&set->type==INT)return;
		if(*(double*)elem==*(double*)(set->elem+i*set->type)&&set->type==DOUBLE)return;
	}
	int mem;
	if(set->card<=64)mem=64*set->type;
	else mem=64*ceil(set->card*set->type/64.0);
	set->card++;
	if (set->card*set->type>mem)set->elem=realloc(set->elem,mem+INITSETSIZE);
	p=set->elem+set->type*i;
	switch(set->type)
	{		
		case CHAR:*(char*)p=*(char*)elem; break;
		case INT:*(int*)p=*(int*)elem; break;
		case DOUBLE:*(double*)p=*(double*)elem; break;
	}	
}
void remElem(void *elem,uset*set) 
{
	if(set->elem==NULL)
	{
		printf("Remove error,the Set has been deleted");exit(-1);
	}
	int i;
	void*p;
	int mem;
	if(set->card<=64)mem=64*set->type;
	else mem=64*ceil(set->card*set->type/64.0);
	for(i=0;i<set->card;i++)
	{	
		p=set->elem+i*set->type;
		if((*(char*)elem==*(char*)p&&set->type==CHAR)\
		||(*(int*)elem==*(int*)p&&set->type==INT)\
		||(*(double*)elem==*(double*)p&&set->type==DOUBLE))
		{
			set->card--;
			
			for(;i<=set->card;i++)
			{
				p=set->elem+i*set->type;
				switch(set->type)
				{
					case CHAR:*(char*)p=*((char*)set->elem+i+1); break;
					case INT:*(int*)p=*((int*)set->elem+i+1); break;
					case DOUBLE:*(double*)p=*((double*)set->elem+i+1); break;
				}	
			} 
			p=NULL;	
			if(set->type*set->card<=mem-INITSETSIZE)set->elem=realloc(set->elem,mem-INITSETSIZE);
			return;
		} 
	}
}

