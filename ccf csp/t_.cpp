#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n,m,x,y,ww,start,end;
LL w[10005];
LL ans;
bool v[10005];

struct node{
	int ep,w;
	node(int _ep,int _w):ep(_ep),w(_w){}
};

vector<node> e[10005];

int dfs(int id,LL cost,LL nowlst){
	if(id==end){
		if(cost<ans)
			ans=cost;
		return 0;
	}
	for(int i=0;i<e[id].size();i++){
		int ep=e[id][i].ep;
		LL ww=e[id][i].w;
		if(v[ep]) continue;
		v[ep]=1;
		if(w[id]<nowlst){
			LL tmp = cost+w[id]*ww;
			dfs(ep,tmp,w[id]);
		} else {
			LL tmp = cost+nowlst*ww;
			dfs(ep,tmp,nowlst);
		}
		v[ep]=0;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",w+i);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&ww);
		e[x].push_back( node(y,ww) );
		e[y].push_back( node(x,ww) );
	}
	for(int c=1;c<=m;c++){
		scanf("%d%d",&start,&end);
		ans = LONG_LONG_MAX;
		memset(v,0,sizeof(v));
		v[start]=1;
		dfs(start,0,w[start]); 
		cout<<ans<<endl;
	}
	return 0;
}
