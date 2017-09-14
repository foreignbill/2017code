#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000 + 50;
int n,dp[maxn]; 
struct node{
	int v,w;
	node(int _v,int _w){
		v=_v;w=_w;
	}
};
vector<node> e[maxn];

int val[maxn];
int dist[maxn];
int res;

struct treetype{
	int Min,Max;
}T[maxn];

void dfs(int id,int fa){
	T[id].Max=val[id];
	T[id].Min=val[id];
	for(auto ep:e[id]){
		if(ep.v==fa) continue;
		dfs(ep.v,id);
		T[ep.v].Max-=ep.w;
		T[ep.v].Min+=ep.w;
		T[id].Max=max(T[id].Max,T[ep.v].Max);
		T[id].Min=min(T[id].Min,T[ep.v].Min);
		res=max(res,T[id].Max-T[id].Min);
	}
}

int main(){
	int T,x,y,z,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){ 
			e[i].clear();
			scanf("%d",&val[i]);
		}
		for(int i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			e[x].push_back(node(y,z));
			e[y].push_back(node(x,z));
		}
		res=0;
		dfs(1,0);
		printf("%d\n",res);
	}
	return 0;
}
