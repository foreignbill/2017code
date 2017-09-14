#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n,m;

char mp[55][55];
bool  v[55][55];
bool ans;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

void dfs(int x,int y,int edx,int edy,int dep){
	if(ans) return;
	for(int c=0;c<4;c++){
		int nowx = x + dx[c];
		int nowy = y + dy[c];
		if(nowx<1||nowx>n) continue;
		if(nowy<1||nowy>m) continue;
		if(mp[nowx][nowy]!=mp[x][y]) continue;
		if(nowx==edx && nowy==edy && dep >= 4){
			ans=1;
			return;
		}
		if(v[nowx][nowy]) continue;
		v[nowx][nowy]=1;
		dfs(nowx,nowy,edx,edy,dep+1);
	}
}

int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				memset(v,0,sizeof(v));
				v[i][j]=1;
				dfs(i,j,i,j,1);
				if(ans) break;
			}
			if(ans) break;
		}
		puts(ans?"Yes":"No");
	}
	return 0;
} 

