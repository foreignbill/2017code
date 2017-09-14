#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int a[50005]; 
int b[50005],t;
int x[50005],y[50005];

map<int,int> S,D;

int main(){
	S[1]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		S.clear();D.clear();
		for(int j=1;j<=k;j++){
			scanf("%d",&b[j]);
			x[b[j]]++;
		}
		for(int j=1;j<=k;j++){
			y[a[j]]++;
		}
		for(int i=1;i<=n;i++){
			if(x[i]>y[i]){
				S[i]=x[i]-y[i]; 
			}
			if(x[i]<y[i]){
				D[i]=y[i]-x[i];
			}
		}
		
	}
	return 0;
}
