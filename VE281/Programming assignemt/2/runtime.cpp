#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int insertion(int n[],int N,int order){
	int i,j,k,t;
	for(int j=1;j<N;j++){
		t=n[j];
		for(i=0;i<=j-1;i++){
			if(n[i]>t){
				for(k=j;k>i;k--)n[k]=n[k-1];	
				n[i]=t;
				break;
			}
		}
	}
	return n[order];
}
int partition(int*n,int left,int right){
	int a,i=left,j=0,k=0,p;
	p=rand()%(right-left+1)+left;	
	if(p>left){
		n[left]=n[left]+n[p];
		n[p]=n[left]-n[p];
		n[left]=n[left]-n[p];
	}
	i=left+1;j=right;
	while(1)
	{
		while(n[i]<n[left]&&i<right)i++;
		while(n[j]>=n[left]&&j>left)j--;
		if(j>i){
			n[i]=n[i]+n[j];
			n[j]=n[i]-n[j];
			n[i]=n[i]-n[j];		
		}		
		else {
			if(j>left){
				n[left]=n[left]+n[j];
				n[j]=n[left]-n[j];
				n[left]=n[left]-n[j];
			}
			break;	
		}	
	}
	p=j;
	return p;
}
void quicksort(int*n,int left,int right){
	int pivotat;
	if(left>=right)return;
	pivotat=partition(n,left,right);
	quicksort(n,left,pivotat-1);
	quicksort(n,pivotat+1,right);
}
int RanSel(int*n,int N,int order){
	int pivot,i;
	if(N==1)return n[0];
	pivot=partition(n,0,N-1);
	if(pivot==order) return n[pivot];
	if(pivot>order) return RanSel(n,pivot,order);
	else return RanSel(n+pivot+1,N-pivot-1,order-pivot-1);
}
int DelSel(int*n,int N,int order){
	int k=N/5,j=N%5,p,i=0,left=0,right=N-1,answer;	
	if(j!=0)k++;
	if(N==1)return n[0];
	int c[k];
	for(p=0;p<k;p++){		
		if((i+4)>=N)c[p]=insertion(n+i,j,j/2);
		else c[p]=insertion(n+i,5,2);
		i+=5;
	}
	p=DelSel(c,k,N/10);
	for(i=0;i<N;i++)if(n[i]==p)break;
	p=i;
	if(p>left){
		n[left]=n[left]+n[p];
		n[p]=n[left]-n[p];
		n[left]=n[left]-n[p];
	}
	i=left+1;j=right;
	while(1)
	{
		while(n[i]<n[left]&&i<right)i++;
		while(n[j]>=n[left]&&j>left)j--;
		if(j>i){
			n[i]=n[i]+n[j];
			n[j]=n[i]-n[j];
			n[i]=n[i]-n[j];		
		}		
		else {
			if(j>left){
				n[left]=n[left]+n[j];
				n[j]=n[left]-n[j];
				n[left]=n[left]-n[j];
			}
			break;	
		}	
	}
	p=j;
	if(p==order) return n[p];
	if(p>order) return DelSel(n,p,order);
	else return DelSel(n+p+1,N-p-1,order-p-1);

}
int main(){

	srand(time(NULL));
	int type,N,order,a1[50],a2[50],a0[50];
	double start,stop,time[6],T[3];	
	
	cout<<"arraysize= ";
	cin>>N;
	int *n=new int[N],*b=new int[N],i,j,k,t;
	for(i=0;i<N;i++)b[i]=rand()%(N*N)-N*N/2;	
	for(type=0;type<3;type++){
		for(i=0;i<N;i++)n[i]=b[i];
		k=0;
		T[type]=0;
		for(order=0;order<N;order+=(N/50)){
			start=clock();
			
			if(type==0)a0[k]=RanSel(n,N,order);
			else if(type==1)a1[k]=DelSel(n,N,order);
			else if(type==2){
				quicksort(n,0,N-1);
				a2[k]=n[order];
			}
			stop=clock();
			time[type]=(stop-start)/CLOCKS_PER_SEC;
			T[type]+=time[type];
			
			k++;
		}
		cout<<"type= "<<type<<"average time="<<T[type]/k<<endl;
	}
	for(k=0;k<50;k++)if(a0[k]!=a1[k]||a1[k]!=a2[k]||a0[k]!=a2[k]){
		cout<<"wrong k="<<k<<" a0[k]= "<<a0[k]<<" a1[k]= "<<a1[k]<<" a2[k]= "<<a2[k]<<endl;
		cout<<"lasta0="<<a0[k-1]<<" next="<<a0[k+1]<<endl;
		cout<<"lasta1="<<a1[k-1]<<" next="<<a1[k+1]<<endl;
		cout<<"lasta2="<<a2[k-1]<<" next="<<a2[k+1]<<endl;
	}
	delete[] n;
	delete[] b;
	return 0;
}
