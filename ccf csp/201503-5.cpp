#include <bits/stdc++.h>

using namespace std;

int w[10005],n,m,x,y,ww,start,end,ans;
int dist[10005];
bool v[10005];

struct node{
	int ep,w;
	node(int _ep,int _w):ep(_ep),w(_w){}
};

vector<node> e[10005];

struct cmp{
	bool operator ()(const int &a,const int &b){
		return dist[a]>dist[b];
	}
};

priority_queue<int,vector<int>,cmp> Q;

int dfs(int id,int cost,int nowlst){
	if(id==end){
		if(cost<ans)
			ans=cost;
		return 0;
	}
	for(int i=0;i<e[id].size();i++){
		int ep=e[id][i].ep;
		int ww=e[id][i].w;
		if(dist[id]+ww==dist[ep]){
			v[ep]=1;
			if(w[id]<nowlst){
				dfs(ep,cost+w[id]*ww,w[id]);
			} else {
				dfs(ep,cost+nowlst*ww,nowlst);
			}
			v[ep]=0;
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",w+i);
	for(int i=1;i<=n-1;i++){
		scanf("%d%d%d",&x,&y,&ww);
		e[x].push_back( node(y,ww) );
		e[y].push_back( node(x,ww) );
	}
	for(int c=1;c<=m;c++){
		scanf("%d%d",&start,&end);
		memset(dist,63,sizeof(dist));
		dist[start]=0;
		Q.push(start);
		while(!Q.empty()){
			int now = Q.top();Q.pop();
			for(int i=0;i<e[now].size();i++){
				int ep=e[now][i].ep;
				int ww=e[now][i].w;
				if(dist[now]+ww<dist[ep]){
					dist[ep]=dist[now]+ww;
					Q.push(ep); 
				}
			}
		}
		ans = INT_MAX;
		memset(v,0,sizeof(v));
		v[start]=1;
		dfs(start,0,w[start]); 
		printf("%d\n",ans);
	}
	
	return 0;
}
