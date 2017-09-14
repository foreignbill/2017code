#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 1000000000;

const int maxn = 200,maxm = 40000;

struct Edge{
	int v, f, nxt;
};

int n, src, sink, m;

int g[maxn + 10];

int nume;

Edge e[maxm * 2 + 20];

void addedge(int u,int v,int c){
	e[++nume].v = v;
	e[nume].f = c;
	e[nume].nxt = g[u];
	g[u] = nume;
	e[++nume].v = u;
	e[nume].f = 0;
	e[nume].nxt = g[v];
	g[v] = nume;
}

void init(){
	memset(g,0,sizeof(g));
	nume = 1;
}

queue<int > Q;

bool vis[maxn + 10];

int dist[maxn + 10];

void bfs(){
	memset(dist,0,sizeof(dist));
	while(!Q.empty()) Q.pop();
	vis[src] = 1;
	Q.push(src);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(int i = g[u];i;i=e[i].nxt)
			if(e[i].f && !vis[e[i].v]){
				Q.push(e[i].v);
				dist[e[i].v] = dist[u] + 1;
				vis[e[i].v] = 1;		
			}
	}
}

int dfs(int u, int delta){
	if(u==sink){
		return delta;
	} else {
		int ret = 0;
		for(int i = g[u]; delta && i; i = e[i].nxt)
			if(e[i].f && dist[e[i].v] == dist[u] + 1){
				int dd = dfs(e[i].v, min(e[i].f, delta));
				e[i].f -= dd;
				e[i^1].f += dd;
				delta -= dd;
				ret += dd;
			}
		return ret;
	}
}

int maxflow(){
	int ret = 0;
	while (1){
		memset(vis, 0 , sizeof(vis));
		bfs();
		if(!vis[sink]) return ret;
		ret += dfs(src,inf);
	}
}

int main(){
	int T;
	cin>>T;
	for(int c=1;c<=T;c++){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u, v, c;
			scanf("%d%d%d",&u,&v,&c);
			addedge(u,v,c);
		}
		src = 1; sink = n;
		int ans = maxflow();
		printf("Case %d: %d\n",c,ans);
	}
	return 0;
} 
