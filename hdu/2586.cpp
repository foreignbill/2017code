#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>

using namespace std;

#define MAXN 40010

struct node{
	int y,next,w;
}e[MAXN*2];

int n,m,len,Link[MAXN],deep[MAXN],f[MAXN],anc[MAXN][25];
int dist[MAXN];
bool v[MAXN]; 

inline int read(){
    int x=0,f=1;  char ch=getchar();
    while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getchar();}
    while(isdigit(ch))  {x=x*10+ch-'0';  ch=getchar();}
    return x*f;
}

void insert(int x,int y,int w){
	e[++len].next=Link[x];
	e[len].w = w;
	Link[x]=len;e[len].y=y;
}

void dfs(int x,int fa){
    anc[x][0]=f[x];
    for(int i=1;i<=20;i++)  anc[x][i]=anc[anc[x][i-1]][i-1];
    for(int i=Link[x];i;i=e[i].next)
        if(e[i].y!=fa){
            f[e[i].y]=x;
            deep[e[i].y]=deep[x]+1;
            dfs(e[i].y,x);
        }
}

int lca(int x,int y){
    if(deep[x]<deep[y])  swap(x,y);
    for(int i=20;i>=0;i--)
        if(deep[anc[x][i]]>=deep[y])  x=anc[x][i];
    if(x==y)  return x;
    for(int i=20;i>=0;i--)
        if(anc[x][i]!=anc[y][i])  x=anc[x][i],y=anc[y][i];
    return f[x];
}

void dfs2(int id){
	for(int i=Link[id];i;i=e[i].next){
		if(v[e[i].y]) continue;
		dist[e[i].y] = dist[id] + e[i].w;
		v[e[i].y] = 1;
		dfs2(e[i].y); 
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int T=read();
	while(T--){
	    n=read();  m=read();
	    for(int i=1;i<n;i++){
			int x=read(),y=read(),w=read();
			insert(x,y,w);
			insert(y,x,w);
		}
		memset(f,0,sizeof(f));
		memset(anc,0,sizeof(anc));
		memset(deep,0,sizeof(deep));
	    deep[1]=1;
		dfs(1,0);
		memset(dist,0,sizeof(dist));
		memset(v,0,sizeof(v));
		v[1]=1;
		dfs2(1);
	    for(int i=1;i<=m;i++){
	        int x=read(),y=read();
	        int father = lca(x,y);
	        int ans = dist[x] + dist[y] - 2*dist[father];
	        cout<<ans<<endl;
	    }
	}
    return 0;
}
