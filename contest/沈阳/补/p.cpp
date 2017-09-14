#include<bits/stdc++.h>
#define maxn 100050
#define inf 0x3f3f3f3f
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
int val[maxn];
int vis[maxn],dis[maxn];
int n;
struct Edge {
  int from, to;
  double dist;
};
struct BellmanFord {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool inq[maxn];     // 是否在队列中
  int d[maxn];     // s到各个点的距离
  int p[maxn];        // 最短路中的上一条弧
  int in[maxn];
  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void AddEdge(int from, int to, double dist) {
    edges.push_back((Edge){from, to, dist});
    m = edges.size();
    G[from].push_back(m-1);
  }
  void spfa(int s) {
    queue<int> Q;
    memset(inq, 0, sizeof(inq));
    memset(in, 0, sizeof in);
    memset(d, 0, sizeof d);
	Q.push(s);
	in[s]=1;
	inq[s] = true;
    while(!Q.empty()) {
      int u = Q.front(); 
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(d[e.to] < d[u] + e.dist) {
          d[e.to] = d[u] + e.dist;
          p[e.to] = G[u][i];
          if(!inq[e.to]) {
		  	in[e.to]++;
          	if(in[e.to]>n) return ;
			Q.push(e.to); inq[e.to] = true; 
		  }
        }
      }
	  Q.pop();
      inq[u] = false;
    }
  }
};
BellmanFord sp;
int main(){
	//freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		sp.init(n+2);
		for(int i=0;i<n;i++) scanf("%d",&val[i]);
		for(int i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			u--;v--; 
			w=-w;
			sp.AddEdge(u,v,w);
			sp.AddEdge(v,u,w);
		}
		int S=n,T=n+1;
		for(int i=0;i<n;i++){
			sp.AddEdge(S,i,val[i]);
			sp.AddEdge(i,T,-val[i]);
		}
		sp.spfa(S);
		printf("%d\n",sp.d[T]);
	}
	return 0;
}
