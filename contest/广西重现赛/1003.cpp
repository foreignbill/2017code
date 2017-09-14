#include <bits/stdc++.h>

#define mp make_pair

using namespace std;
typedef long long ll;

const int maxn = 100005;

vector<pair<int,int> > e[maxn];

int du[maxn],u,v,n,m;
ll cnt[maxn<<2];
struct node{
	int u,v;
}info[maxn<<2];

struct Node{
	int idi,idep;
	Node(){}
	Node(int _idi,int _idep){
		idi=_idi;
		idep=_idep;
	}
}a[maxn<<2];

int main(){	
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++)
			e[i].clear();
		memset(a,0,sizeof a);
		memset(du,0,sizeof du);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			du[u]++;du[v]++;
			info[i].u=u;
			info[i].v=v;
		}
		for(int i=1;i<=m;i++){
			u=info[i].u;v=info[i].v;
			if(du[u] < du[v] || (du[u] == du[v] && u < v))
				e[u].push_back(mp(v,i));
			else e[v].push_back(mp(u,i));
		}
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=m;i++){
			u=info[i].u;v=info[i].v;
			for(auto ep:e[u]) a[ep.first]=Node(i,ep.second);
			for(auto ep:e[v]){
				if(a[ep.first].idi==i){
					cnt[i]++;
					cnt[ep.second]++;
					cnt[a[ep.first].idep]++;
				}
			}
		}
		ll res = 0;
		for(int i=1;i<=m;i++)
			res += (cnt[i]-1ll)*cnt[i]/2ll;
		printf("%lld\n",res);
	}
	return 0;
} 
