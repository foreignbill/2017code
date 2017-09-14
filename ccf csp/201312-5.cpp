#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};

bool v[55][55],vis[55][55],check;

char g[55][55];

int Sx,Sy;

struct node{
	int x,y;
	node(int _x,int _y):x(_x),y(_y){}
};

queue<node> Q;

bool dfs(int x,int y){
	if(g[x][y]=='T') check=true;
	if(g[x][y]=='+'||g[x][y]=='S'||g[x][y]=='T'){
		for(int i=0;i<4;i++){
			int nowx=x+dx[i];
			int nowy=y+dy[i];
			if(g[nowx][nowy]=='#') continue;
			if(vis[nowx][nowy]) continue;
			vis[nowx][nowy]=1;
			dfs(nowx,nowy);
		}
	}
	if(g[x][y]=='-'){
		for(int i=2;i<4;i++){
			int nowx=x+dx[i];
			int nowy=y+dy[i];
			if(g[nowx][nowy]=='#') continue;
			if(vis[nowx][nowy]) continue;
			vis[nowx][nowy]=1;
			dfs(nowx,nowy);
		}
	}
	if(g[x][y]=='|'){
		for(int i=0;i<2;i++){
			int nowx=x+dx[i];
			int nowy=y+dy[i];
			if(g[nowx][nowy]=='#') continue;
			if(vis[nowx][nowy]) continue;
			vis[nowx][nowy]=1;
			dfs(nowx,nowy);
		}
	}
	if(g[x][y]=='.'){
		int i=1;
		int nowx=x+dx[i];
		int nowy=y+dy[i];
		if(g[nowx][nowy]=='#') return 0;
		if(vis[nowx][nowy]) return 0;
		vis[nowx][nowy]=1;
		dfs(nowx,nowy);
	}
	return 0;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++) g[i][j]='#';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			g[i][j]=getchar();
			if(g[i][j]=='S'){
				Sx=i;
				Sy=j;
			}
		}
		getchar();
	}
	
	while(!Q.empty()) Q.pop();
	memset(v,0,sizeof(v));
	v[Sx][Sy]=1;
	Q.push(node(Sx,Sy));
	while(!Q.empty()){
		node now = Q.front();Q.pop();
		int x=now.x,y=now.y;
		if(g[x][y]=='+'||g[x][y]=='S'||g[x][y]=='T'){
			for(int i=0;i<4;i++){
				int nowx=x+dx[i];
				int nowy=y+dy[i];
				if(g[nowx][nowy]=='#') continue;
				if(v[nowx][nowy]) continue;
				v[nowx][nowy]=1;
				Q.push(node(nowx,nowy));
			}
		}
		if(g[x][y]=='-'){
			for(int i=2;i<4;i++){
				int nowx=x+dx[i];
				int nowy=y+dy[i];
				if(g[nowx][nowy]=='#') continue;
				if(v[nowx][nowy]) continue;
				v[nowx][nowy]=1;
				Q.push(node(nowx,nowy));
			}
		}
		if(g[x][y]=='|'){
			for(int i=0;i<2;i++){
				int nowx=x+dx[i];
				int nowy=y+dy[i];
				if(g[nowx][nowy]=='#') continue;
				if(v[nowx][nowy]) continue;
				v[nowx][nowy]=1;
				Q.push(node(nowx,nowy));
			}
		}
		if(g[x][y]=='.'){
			int i=1;
			int nowx=x+dx[i];
			int nowy=y+dy[i];
			if(g[nowx][nowy]=='#') continue;
			if(v[nowx][nowy]) continue;
			v[nowx][nowy]=1;
			Q.push(node(nowx,nowy));
		}
	}
	
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(v[i][j]) cnt++;
	
	if(cnt>1){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(v[i][j]){
					memset(vis,0,sizeof(vis));
					vis[i][j]=1;
					check=false;
					dfs(i,j);
					if(check) ans++;
				}
	} else {
		puts("I'm stuck!");
		return 0;
	}
	
	printf("%d\n",cnt-ans);
	
	return 0;
} 
