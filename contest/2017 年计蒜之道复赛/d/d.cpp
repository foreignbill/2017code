#include <bits/stdc++.h>

#define LL long long

using namespace std;

struct node{
	int v;
	LL w;
	node(int _v,LL _w):v(_v),w(_w){} 
};

vector<node> e[60005];
LL dist[60005];

int n,m,k,x,y,m1,m2,u,v,w,start,endpoint,now,ep;

struct cmp{
	bool operator ()(const int &a,const int &b){
		return dist[a]>dist[b];
	}
};

priority_queue<int,vector<int>,cmp> Q;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			e[x].push_back(node(i+n,0));
			e[i+n+m].push_back(node(x,0));
		}
	}
	scanf("%d",&m1);
	for(int i=1;i<=m1;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(node(v,w));
		e[v].push_back(node(u,w));
	}
	scanf("%d",&m2);
	for(int i=1;i<=m2;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u+n].push_back(node(v+n+m,w));
		e[v+n].push_back(node(u+n+m,w)); 
	}
	scanf("%d%d",&start,&endpoint);
	memset(dist,0x3f,sizeof dist);
	dist[start]=0;
	Q.push(start);
	while(!Q.empty()){
		now = Q.top();Q.pop();
		for(int i=0;i<e[now].size();i++){
			ep=e[now][i].v;
			LL w=e[now][i].w;
			if(dist[now]+w<dist[ep]){
				dist[ep]=dist[now]+w;
				Q.push(ep);	
			}
		}
	}
	if(dist[endpoint]>=1e12) cout<<"-1\n";
	else cout<<dist[endpoint]<<endl;
	return 0;
} 
