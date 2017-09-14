#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+10;
vector<int>e[maxn];
int n; 
int vis[maxn],deep[maxn],f[maxn],anc[maxn][25];
int dis[maxn];
void dfs(int x,int fa){
    anc[x][0]=f[x];
    for(int i=1;i<=20;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
    for(auto next:e[x]){
        if(next!=fa){
            f[next]=x;
            deep[next]=deep[x]+1;
            dfs(next,x);
        }
    }
}
int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return f[x];
}

struct node{
	int x,y,z;
}info[maxn];

bool comp(node A,node B){
	return deep[A.z]>deep[B.z];
} 

void solve(int x,int y){
	if(vis[x]) return;
	vis[x]=1;
	for(auto ep:e[x]){
		if(ep==y) continue;
		solve(ep,x);
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n+1;i++)
			e[i].clear();
		memset(vis,0,sizeof vis);
		memset(deep,0,sizeof deep);
		memset(anc,0,sizeof anc);
		for(int i=1;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x++;y++;
			e[x].push_back(y);e[y].push_back(x);
		}
		dfs(1,0);
		int q,tot=0;
		scanf("%d",&q);
		for(int cnt=1;cnt<=q;cnt++){
			int x,y;
			scanf("%d%d",&x,&y);
			x++;y++;
			info[++tot]=node{x,y,lca(x,y)};
		}
		sort(info+1,info+1+tot,comp);
		int res=0;
		for(int i=1;i<=tot;i++){
			if(vis[info[i].x] || vis[info[i].y]) continue;
			res++;
			solve(info[i].z,anc[info[i].z][0]);
		}
		printf("%d\n",res);
	}
	return 0;
} 
