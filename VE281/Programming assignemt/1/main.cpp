#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int partition(int*n,int left,int right,int m){
	int a,i=left,j=0,k=0,c[right-left+1],p;
	p=rand()%(right-left+1)+left;	
	if(p>left){
		n[left]=n[left]+n[p];
		n[p]=n[left]-n[p];
		n[left]=n[left]-n[p];
	}
	if(m==4){
		i++;
		k=right-left;
		while(j!=k){
			if(n[i]<n[left])c[j++]=n[i++];
			else c[k--]=n[i++];
		}
		c[j]=n[left];
		p=j+left;
		k=0;
		for(i=left;i<=right;i++)n[i]=c[k++];
	}
	else {

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
	}
	return p;
}
void quicksort(int*n,int left,int right,int m){
	int pivotat;
	if(left>=right)return;
	pivotat=partition(n,left,right,m);
	quicksort(n,left,pivotat-1,m);
	quicksort(n,pivotat+1,right,m);
}
void merge(int*n,int left,int mid,int right){
	int i=left,j=mid+1,k=0,c[right-left+1];
	while(i<mid+1&&j<right+1){
		if(n[i]<=n[j])c[k++]=n[i++];
		else c[k++]=n[j++];
	}
	if(i>=mid+1)while(j<right+1)c[k++]=n[j++];
	else while(i<mid+1)c[k++]=n[i++];
	k=0;
	for(i=left;i<=right;i++)n[i]=c[k++];
}
void mergesort(int*n,int left,int right){
	if (left>=right)return;
	int mid=(right+left)/2;
	mergesort(n,left,mid);
	mergesort(n,mid+1,right);
	merge(n,left,mid,right);
} 
int main(){
	srand(time(NULL));
	int type,N;
	cin>>type>>N;
	int n[N],i,j,k,t;
	for(i=0;i<N;i++)cin>>n[i];
	switch (type){
		case 0:{
			for(j=N-2;j>=0;j--){
				for(i=0;i<=j;i++){
					if(n[i]>n[i+1]){
						t=n[i+1];
						n[i+1]=n[i];
						n[i]=t;
					}
				}
			}		
			break;
		}
		case 1:{
			for(j=1;j<N;j++){
				t=n[j];
				for(i=0;i<=j-1;i++){
					if(n[i]>t){
						for(k=j;k>i;k--)n[k]=n[k-1];	
						n[i]=t;
						break;
					}
				}
			}
			break;
		}	
		case 2:{
			for(i=0;i<N-1;i++){
				t=n[i];
				k=i;
				for(j=i;j<N;j++){
					if(n[j]<t){
						t=n[j];
						k=j;
					}
				}
				n[k]=n[i];
				n[i]=t;
			}
			break;
		}
		case 3:{
			mergesort(n,0,N-1);
			break;
		}
		case 4:{
			quicksort(n,0,N-1,4);
			break;
		}
		case 5:{
			quicksort(n,0,N-1,5);
			break;
		}
	}
	for(i=0;i<N;i++)cout<<n[i]<<endl;
	return 0;
}
