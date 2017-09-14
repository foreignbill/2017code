#include <bits/stdc++.h>

using namespace std;

int n,m;

int a[22][10005];
int f[22][10005];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				f[i][j]=-20000000;
			}
		f[1][1]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				f[i][j]+=a[i][j];
				if(f[i][j]>f[i+1][j])
					f[i+1][j]=f[i][j];
				if(f[i][j]>f[i][j+1])
					f[i][j+1]=f[i][j];
				for(int t=j+j;t<=m;t+=j)
					if(f[i][j]>f[i][t])
						f[i][t]=f[i][j];
			} 
		printf("%d\n",f[n][m]);
	}
	return 0;
} 
