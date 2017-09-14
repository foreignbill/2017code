#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
#define MAXN 100010
struct node{
	int y,next,w;
}e[MAXN*2];

int n,m,len,head[MAXN],deep[MAXN],f[MAXN],anc[MAXN][25];

inline int read(){
    int x=0,f=1;  char ch=getchar();
    while(!isdigit(ch))  {if(ch=='-')  f=-1;  ch=getchar();}
    while(isdigit(ch))  {x=x*10+ch-'0';  ch=getchar();}
    return x*f;
}

void insert(int x,int y,int w){
	e[++len].next=head[x];
	e[len].w=w;
	head[x]=len;e[len].y=y;
}

void dfs(int x,int fa){
    anc[x][0]=f[x];
    for(int i=1;i<=20;i++)  anc[x][i]=anc[anc[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].next)
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

int main(){
	freopen("input.txt","r",stdin);
	while(cin>>n){
		len=0;
		memset(head,0,sizeof head);
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
	}
    return 0;
}
