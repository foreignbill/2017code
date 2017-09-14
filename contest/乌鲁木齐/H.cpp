#include <bits/stdc++.h>

using namespace std;
const int maxn=20005;
const int maxm=200010;
int head[maxn],n,m;
int e[maxm],nxt[maxm],w[maxm],cnt,x,y,z;
int dist[maxn];
bool vis[maxn];
int Q[maxm<<2];

int main(){
	int T;
	cin>>T;
	while(T--){
		memset(head,-1,sizeof head);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			nxt[i]=head[x];
			e[i]=y;
			w[i]=z; 
			head[x]=i;
		}
		int f=1,r=n;
		for(int i=1;i<=n;i++)
			Q[i]=i;
		memset(vis,0,sizeof vis);
		memset(dist,0,sizeof dist);
		while(f<=r){
			int now = Q[f];
			for(int k=head[now];k!=-1;k=nxt[k]){
				int ep=e[k];
				if(dist[now]+w[k] > dist[ep]){
					dist[ep] = dist[now] + w[k];
					if(vis[ep]==0){
						Q[++r]=ep;
						vis[ep]=1;
					}
				}
			}
			vis[now]=0;
			f++;
		}
		int res=dist[1];
		for(int i=2;i<=n;i++)
			res=max(res,dist[i]);
		printf("%d\n",res);
	}
	return 0;
}
