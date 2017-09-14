#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

char g[105][105];
bool v[105][105];
char ch;
int n,m,q,tp,x1,y1,x2,y2;

void dfs(int x,int y,char ch){
	if(x<0||x>=n) return;
	if(y<0||y>=m) return;
	if(g[x][y]=='+') return;
	if(g[x][y]=='-') return;
	if(g[x][y]=='|') return;
	if(v[x][y]) return;
	v[x][y]=true;
	g[x][y]=ch;
	for(int i=0;i<4;i++){
		int nowx=x+dx[i];
		int nowy=y+dy[i];
		dfs(nowx,nowy,ch);
	}
}

int main(){
	cin>>m>>n>>q;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			g[i][j]='.';
	for(int i=1;i<=q;i++){
		cin>>tp;
		if(tp==0){
			cin>>y1>>x1>>y2>>x2;
			if(x1==x2){
				if(y1>y2) swap(y1,y2);
				for(int y=y1;y<=y2;y++) 
					if(g[x1][y]=='+'||g[x1][y]=='|') g[x1][y]='+';
					else g[x1][y]='-';
			}
			if(y1==y2){
				if(x1>x2) swap(x1,x2);
				for(int x=x1;x<=x2;x++) 
					if(g[x][y1]=='-'||g[x][y1]=='+') g[x][y1]='+';
					else g[x][y1]='|';
			}
		}
		else{
			cin>>y1>>x1>>ch;
			memset(v,0,sizeof(v));
			dfs(x1,y1,ch);
		}
	}
	for(int i=n-1;i>=0;i--){
		
		for(int j=0;j<m;j++)
			putchar(g[i][j]);
		puts(""); 
	} 
	return 0;
} 
