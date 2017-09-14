#include <bits/stdc++.h>

using namespace std;
const int maxn = 200005;
typedef long long ll; 
int n;
int c[maxn],order[maxn],T,tot;
int size[maxn];
ll ans;
vector<int> e[maxn];
stack<int> s[maxn];

void dfs(int id,int fa){
	order[id]=++tot;
	size[id]=1;
	for(auto ep:e[id]){
		if(ep==fa) continue;
		dfs(ep,id);
		size[id] += size[ep];
		int tmp = size[ep];
		while(!s[c[id]].empty() && order[s[c[id]].top()] > order[id]){
			tmp -= size[s[c[id]].top()]; 
			s[c[id]].pop();
		}
		ans -= (ll)tmp*(tmp-1)/2;
	}
	s[c[id]].push(id);
}

int main(){
	int T=1;
	while(~scanf("%d",&n)){
		for(int i=0;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans=(ll)n*n*(n-1)/2;
		tot=0;
		dfs(1,0);
		for(int i=1;i<=n;i++){
			int tmp = n;
			while(!s[i].empty()){
				tmp -= size[s[i].top()];
				s[i].pop();
			}
			ans -= (ll)tmp*(tmp-1)/2;
		}
		printf("Case #%d: %lld\n",T++,ans);
	}
	return 0;
} 
