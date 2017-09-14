#include<bits/stdc++.h>
#define maxn 400050
#define LL long long
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf=0x3f3f3f3f;
const int base=200000;
map<string,int>ss;
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost){}
};
struct MCMF{
	int n,m,s,t;
	vector<Edge>edges;
	vector<int>G[maxn];
	int inq[maxn],p[maxn];
	LL d[maxn],a[maxn];
	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int cap,int cost){
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool BellmanFord(int s,int t,LL &flow,LL& cost){
		for(int i=0;i<n;i++) d[i]=inf;
		memset(inq,0,sizeof(inq));
		d[s]=0,inq[s]=1,p[s]=0,a[s]=inf;
		queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();  Q.pop();
			inq[u]=0;
			for(int i=0;i<G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
					d[e.to]=d[u]+e.cost;
					p[e.to]=G[u][i];
					a[e.to]=min(a[u],(LL)e.cap-e.flow);
					if(!inq[e.to]){
						Q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==inf) return false;
		flow+=a[t];
		cost+=d[t]*a[t];
		int u=t;
		while(u!=s){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return true;
	}
	void Mincost(int s,int t){
		LL flow=0,cost=0;
		while(BellmanFord(s,t,flow,cost));
		if(flow==2) printf("%lld\n",cost);
		else printf("-1\n");
	}
}mc;
int main(){
	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		mc.init(maxn);
		ss.clear();
		int nn=0,mm;
		scanf("%d",&mm);
		while(mm--){
			char s1[100],s2[100];
			int w;
			scanf("%s%s%d",s1,s2,&w);
			if(!ss.count(s1)){
				nn++;
				ss[s1]=nn;
				mc.AddEdge(ss[s1],ss[s1]+base,1,0);
				mc.AddEdge(ss[s1]+base,ss[s1],1,0);
			}
			if(!ss.count(s2)){
				nn++;
				ss[s2]=nn;
				mc.AddEdge(ss[s2],ss[s2]+base,1,0);
				mc.AddEdge(ss[s2]+base,ss[s2],1,0);
			}
			mc.AddEdge(ss[s1]+base,ss[s2],1,w);
			mc.AddEdge(ss[s2]+base,ss[s1],1,w);
		}
		int S=ss["Shanghai"]+base,T=nn+1;
		mc.AddEdge(ss["Xian"]+base,T,1,0);
		mc.AddEdge(ss["Dalian"]+base,T,1,0);
		mc.Mincost(S,T);
	}
	return 0;
}

