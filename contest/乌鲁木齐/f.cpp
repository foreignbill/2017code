#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define mod 1000000007
using namespace std;
const ll inf=1e18;
struct edge{
    int t;ll cost;
    edge(){}
    edge(int u,ll v):t(u),cost(v){}
};
int n,m;
vector<edge>g[maxn];
ll dist[maxn];
void init(){
    for(int i=0;i<maxn;i++){
        g[i].clear();
    }
}
void input(){
    for(int i=1;i<=m;i++){
        int k,x;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&x);
            g[x].push_back(edge(n+i,0LL));
            g[n+m+i].push_back(edge(x,0LL));
        }
    }
    int m1,m2;
    scanf("%d",&m1);
    for(int i=0;i<m1;i++){
        int u,v;ll c;
        scanf("%d%d%I64d",&u,&v,&c);
        g[u].push_back(edge(v,c));
        g[v].push_back(edge(u,c));
    }
    scanf("%d",&m2);
    for(int i=0;i<m2;i++){
        int u,v;
        ll c;
        scanf("%d%d%I64d",&u,&v,&c);
        g[n+u].push_back(edge(n+m+v,c));
        g[n+v].push_back(edge(n+m+u,c));
    }
}
void solve(){
    int s,t;
    scanf("%d%d",&s,&t);
  //  cout<<s<<" "<<t<<endl;
    priority_queue< pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int> >>que;
    for(int i=1;i<=n+2*m;i++){dist[i] =inf;}
    dist[s]=0LL;
    que.push(make_pair(0LL,s));
    while(!que.empty()){
        pair<ll,int> p=que.top();
        que.pop();
        int v=p.second;
      //  cout<<"v: "<<v<<endl;
        if(dist[v]<p.first) continue;
        for(int i=0;i<g[v].size();i++){
            edge e=g[v][i];
            if(dist[e.t]>dist[v]+e.cost){
                dist[e.t]=dist[v]+e.cost;
                que.push(make_pair(dist[e.t],e.t));
            }
        }
    }
    if(dist[t]!=inf){
        printf("%I64d\n",dist[t]);
    }
    else {
        puts("-1");
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)==2){
        init();
        input();
        solve();
    }
    return 0;
}
