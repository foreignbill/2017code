#include <bits/stdc++.h>

using namespace std;

int head[20005];
int nxt[10000000],e[10000000],w[10000000];
vector<int> incity[20005];
int dist[20005];
int n,m,k,x,y,m1,m2,u,v,ww,start,endpoint,now,ep,top;

struct cmp{
	bool operator ()(const int &a,const int &b){
		return dist[a]>dist[b];
	}
};

priority_queue<int,vector<int>,cmp> Q;

void add(int u,int v,int ww){
	top++;
	e[top]=v;
	w[top]=ww;
	nxt[top]=head[u];
	head[u]=top;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&x);
			incity[i].push_back(x);
		}
	}
	top=0;
	scanf("%d",&m1);
	for(int i=1;i<=m1;i++){
		scanf("%d%d%d",&u,&v,&ww);
		add(u,v,ww);
		add(v,u,ww);
	}
	scanf("%d",&m2);
	for(int i=1;i<=m2;i++){
		scanf("%d%d%d",&u,&v,&ww);
		for(int I=0;I<incity[u].size();I++)
			for(int J=0;J<incity[v].size();J++){
				if(top>9500000) continue;
				x=incity[u][I],y=incity[v][J];
				add(x,y,ww);
				add(y,x,ww);
			}
	}
	scanf("%d%d",&start,&endpoint);
	memset(dist,63,sizeof dist);
	dist[start]=0;
	Q.push(start);
	while(!Q.empty()){
		now=Q.top();Q.pop();
		for(int i=head[now];i;i=nxt[i]){
			if(dist[now]+w[i]<dist[e[i]]){
				dist[e[i]]=dist[now]+w[i];
				Q.push(e[i]);
			}
		}
	}
	cout<<dist[endpoint]<<endl;
	return 0;
}
