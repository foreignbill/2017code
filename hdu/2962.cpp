#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

int C,R,u,v,w,h,stx,edx,height; 

const int INF = 1061109567;

struct Edge{
	int v,w,h;
	Edge(int _v,int _w,int _h):v(_v),w(_w),h(_h){}
};

vector<Edge> e[11111];

int dist[11111];

bool vis[11111];

void spfa(int stx,int limits){
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	Q.push(stx);
	memset(dist,63,sizeof(dist));
	dist[stx] = 0;
	memset(vis,0,sizeof(vis));
	vis[stx] = 1;
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		vis[now] = 0;
		for(int i=0;i<e[now].size();i++){
			if(e[now][i].h<limits) continue;
			if(dist[now] + e[now][i].w < dist[e[now][i].v]){
				dist[e[now][i].v] = dist[now] + e[now][i].w;
				if(!vis[e[now][i].v]){
					Q.push(e[now][i].v);
					vis[e[now][i].v] = 1;
				}
			}
		}
	}
}

int main(){
	int id = 1;
	while(scanf("%d%d",&C,&R),(C||R)){
		for(int i=1;i<=C;i++) e[i].clear();
		for(int i=1;i<=R;i++){
			scanf("%d%d%d%d",&u,&v,&h,&w);
			if(h==-1) h = INF;
			e[u].push_back(Edge(v,w,h));
			e[v].push_back(Edge(u,w,h));
		}
		scanf("%d%d%d",&stx,&edx,&height);
		if(height==-1) height = INF;
		int L = 1 ,R = height;
		int ans = -1 , answ = -1;
		while(L<=R){
			int mid = L + R >> 1;
			spfa(stx,mid);
			if(dist[edx] != INF){
				L = mid + 1;
				ans = mid;
				answ = dist[edx];
			} else {
				R = mid - 1;
			}
		}
		if(id>1) puts("");
		printf("Case %d:\n",id++);
		if(answ!=-1){
			printf("maximum height = %d\n",ans);
			printf("length of shortest route = %d\n",answ);
		} else {
			puts("cannot reach destination");
		}
	}
	return 0;
} 
