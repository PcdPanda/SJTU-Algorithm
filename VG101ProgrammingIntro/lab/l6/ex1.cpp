#include <iostream>
#include <stdio.h>
#include "grade.h"
using namespace std;
static const char GRADES[] = {'F','F','F','F','F','F','D','C','B','A','A'};
int main()
{
	Grade g;
	int prct;
	cout<<"Input two space seprated grades (1st in %d, 2nd in letter): "<<endl;
	cin>>prct;
	getchar();
	g.GradePrct(prct);
	g.printGrade();
	g.GradeLtr(getchar());
	g.printGrade();
}
void Grade::GradePrct(int dprct)
{
	prct=dprct;
	ltr = GRADES[dprct / 10];
}
void Grade::GradeLtr(int dltr)
{
	ltr=dltr;
	prct = 100 - (dltr - 'A') * 10 - 5;
}
void Grade::printGrade()
{
	cout<<"Grade: "<<prct<<" -> "<<ltr<<endl;
}
