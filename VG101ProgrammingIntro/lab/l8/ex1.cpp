#include <iostream>
#include <string> 
#include <vector>
#include <stack> 
#include <queue>
using namespace std;
void ex11()
{
	char a[100],b;int i=0,j;
	cin>>a;
	while(a[i]!='\0')i++;
	for(j=0;j<=(i/2);j++){b=a[j];a[j]=a[i-j-1];a[i-j-1]=b;}
	cout<<a<<endl;
}
void ex12()
{
	vector<char>a;string c;
	cin>>c;
	for(int d=1;d<=c.size();d++){a.push_back(c[d-1]);}
	vector<char>::reverse_iterator i;
	for(i=a.rbegin();i!=a.rend();i++)cout<<*i;
}
void ex13()
{
	stack<char>a;string c;cin>>c;
	for(int d=1;d<=c.size();d++){a.push(c[d-1]);}
	while(!a.empty()){cout<<a.top();a.pop();}
}
void ex21(){char a[100];cin>>a;cout<<a<<endl;}
void ex22()
{
	vector<char>a;char b;string c;int d;
	cin>>c;
	for(int d=1;d<=c.size();d++){a.push_back(c[d-1]);}
	vector<char>::iterator i;
	for(i=a.begin();i!=a.end();i++)cout<<*i;
}
void ex23()
{
	queue<char>a;string c;
	cin>>c;
	for(int d=1;d<=c.size();d++){a.push(c[d-1]);}
	while(!a.empty()){cout<<a.front();a.pop();}
} 
int main()
{
	ex11();
	//ex12();
	//ex13();
	//ex21();
	//ex22();
	//ex23();
	return 0;
} 
