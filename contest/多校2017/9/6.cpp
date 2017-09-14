#include<bits/stdc++.h>
#define maxn 100050
#define LL long long
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
const LL INF=(LL)1e18;
int n,m;
LL dis[maxn],ans;
int a[maxn];
int hashh[maxn];
struct node{
	int x;
	LL id;
	node(int u,LL w){x=u,id=w;}
	bool operator < (const node &a) const{
		return id>a.id;
	}
};
vector<node>e[maxn];
void init(){
	for(int i=0;i<=n;i++) e[i].clear();
	for(int i=1;i<maxn;i++) dis[i]=INF;
	mm(a,0),mm(hashh,0);
	ans=INF;
}
void DJ(int s){
	priority_queue<node>q;
	q.push(node(s,0));
	while(!q.empty()){
		node now=q.top();
		q.pop();
		int len=e[now.x].size();
		for(int i=0;i<len;i++){
			node next=e[now.x][i];
			if(next.x != s && dis[next.x]>now.id+next.id){
				dis[next.x]=now.id+next.id;
				//if(hashh[next.x]>0 && next.x!=s) ans=min(ans,dis[next.x]);
				q.push(node(next.x,dis[next.x]));
			}
		}
	}
}
int flag=1;
int main(){
//	freopen("input.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			LL w;
			scanf("%d%d%lld",&u,&v,&w);
			e[u].push_back(node(v,w));
		}
		int k; scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x; scanf("%d",&x);
			a[i]=x,hashh[x]++;
		}
		for(int i=1;i<=k;i++) DJ(a[i]);
		LL Min = LONG_LONG_MAX;
		for(int i=1;i<=k;i++)
			Min = min(Min,dis[a[i]]);
		printf("Case #%d: %lld\n",flag++,Min);
	}
	return 0;
}
