#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll inf=LONG_LONG_MAX / 4LL;
struct Edge{
    int v;
	ll w;
};
vector<Edge>vet[MAXN];
struct Node{
    int v;
	ll dist;
    int mark;
    bool operator < (const Node &p) const {
        if(p.dist!=dist)
            return p.dist<dist;
 
        return p.v<v;
    }
};
int n,m;
ll dist[MAXN][3];
int dp[MAXN][3];
bool visited[MAXN][3];
bool ison[MAXN];
ll Min; 
 
void Dijkstra(int start,int end){
    for(int i=1;i<=n;i++){
        dist[i][1]=dist[i][2]=inf;
    }
    memset(dp,0,sizeof(dp));
    memset(visited,false,sizeof(visited));
    priority_queue<Node>Q;
    Node p,q;
    dist[start][1]=0;
    dp[start][1]=1;
    p.dist=0,p.mark=1,p.v=start;
    Q.push(p);
    while(!Q.empty()){
        p=Q.top();
        Q.pop();
        if(visited[p.v][p.mark])continue;
        visited[p.v][p.mark]=true;
        for(int i=0;i<vet[p.v].size();i++){
            int v=vet[p.v][i].v;
            int w=vet[p.v][i].w;
            if(!visited[v][1]&&p.dist+w<dist[v][1]){
            	if(w < Min) Min = w;
                if(dist[v][1]!=inf){
                    q.v=v,q.dist=dist[v][1],q.mark=2;
                    dist[v][2]=dist[v][1];
                    dp[v][2]=dp[v][1];
                    Q.push(q);
                }
                dist[v][1]=p.dist+w;
                dp[v][1]=dp[p.v][p.mark];
                q.v=v,q.dist=dist[v][1],q.mark=1;
                Q.push(q);
            }else if(!visited[v][1]&&p.dist+w==dist[v][1]){
                dp[v][1]+=dp[p.v][p.mark];
            }else if(!visited[v][2]&&p.dist+w<dist[v][2]){
                dist[v][2]=p.dist+w;
                dp[v][2]=dp[p.v][p.mark];
                q.dist=dist[v][2],q.v=v,q.mark=2;
                Q.push(q);
            }else if(!visited[v][2]&&p.dist+w==dist[v][2]){
                dp[v][2]+=dp[p.v][p.mark];
            }
        }
    }
}
 
int main(){
	int u,v;ll w;
	int T;
	scanf("%d",&T);
    while(T--){
    	Min = LONG_LONG_MAX;
    	scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)vet[i].clear();
        for(int i=1;i<=m;i++){
            scanf("%d%d%lld",&u,&v,&w);
            Edge p;
            p.v=v,p.w=w;
            vet[u].push_back(p);
            p.v=u;
            vet[v].push_back(p);
        }
        Dijkstra(1,n);
        if(dp[n][1] >= 2){
        	printf("%lld\n",dist[n][1]);
        } else {
        	if(dp[n][2] >= 1){
        		printf("%lld\n",dist[n][2]);
        	} else {
				printf("%lld\n",dist[n][1] + Min + Min);
        	}
        }
    }
    return 0;
}
