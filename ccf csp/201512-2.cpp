#include <cstdio>
#include <cstring>

using namespace std;

int g[33][33],ans[33][33];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&g[i][j]);
			ans[i][j]=g[i][j];
		}
	for(int i=1;i<=n;i++){
		int f=1,r=1;
		while(r<=m){
			
			while(g[i][f]==g[i][r]) r++;r--;
			if(r-f+1>=3){
				for(int ii=f;ii<=r;ii++) ans[i][ii]=0;
			}
			f=r+1;
			r=f;
			if(f>m) break; 
		}
	}
	
	for(int j=1;j<=m;j++){
		int f=1,r=1;
		while(r<=n){
			
			while(g[f][j]==g[r][j]) r++;r--;
			if(r-f+1>=3){
				for(int ii=f;ii<=r;ii++) ans[ii][j]=0;
			}
			f=r+1;
			r=f;
			if(f>n) break; 
		}
	}
	
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<m;j++)
			printf("%d ",ans[i][j]);
		printf("%d\n",ans[i][m]);
	}
	return 0;
}
