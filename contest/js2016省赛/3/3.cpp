#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int data[11];

struct node{
	int a[11];
}p[111111];

int n,k,top;
int tmp[111];
	
inline bool isequal(int a[],int b[],int n){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	for(int i=n+1;i<=n+n;i++) tmp[i]=a[i-n];
	for(int pos=0;pos<n;pos++){
		bool ok = 1;
		for(int i=1;i<=n;i++)
			if( tmp[pos+i]!=b[i]) ok=0;
		if(ok) return 1;
	}
	return 0;
}

inline void dfs(int id,int k){
	if(id==n+1){
		bool flag = 1;
		for(int i=1;i<=top;i++)
			if(isequal(p[i].a,data,n)){
				flag = 0;
				break;
			}
		if(!flag) return;
		top++;
		for(int i=1;i<=n;i++)
			p[top].a[i]=data[i];
		return;
	}
	for(int i=0;i<k;i++){
		data[id]=i;
		dfs(id+1,k);
	}
}

int main(){
	while(cin>>n>>k){
		top=0; 
		dfs(1,k);
		/*for(int i=1;i<=top;i++){
			for(int j=1;j<=n;j++)
				printf("%d",p[i].a[j]);
			puts("");
		}*/
		printf("%d\n",top);
	}
	return 0;
} 
