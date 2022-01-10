#include <iostream>
#include <cmath> 
#include <ctime>
#include <fstream>
#include <GL/freeglut.h>
using namespace std;
void ex2()
{
	srand(time(NULL));
	ofstream a("ex2.txt",ios::app);
	a<<"Setup:\n";
	int msta=100,mstr=100,mpre=100,sta=100,str=80,pre=50,sil=50;
	a<<"Monsters(max:stamina,strength,precision):"<<msta<<mstr<<mpre<<endl;
	a<<"Prince(stamina,strength,precision,silence):"<<sta<<str<<pre<<sil<<endl;	
	a<<"Game:\n";
	a.close();
}
