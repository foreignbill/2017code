#include <bits/stdc++.h>

using namespace std;

vector<int> e[2005]; 

bool flag;

bool vis[2005];
bool g[1005][1005];

void dfs(int id){
	for(auto ep:e[id]){
		if(vis[ep]) continue;
		vis[ep]=1;
		dfs(ep);
	}
}

int main(){
	int T,n,m,u,v;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
		}
		memset(g,0,sizeof g);
		flag = 1;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof vis);
			vis[i]=1;
			dfs(i);
			int cnt = 0;
			for(int j=1;j<=n;j++)
				if(vis[j]) g[i][j]=1;
		} 
		int cnt = 0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(g[i][j] || g[j][i]) cnt++;
		if(cnt == (n-1)*n/2) flag = 1;
		else flag = 0;
		if(flag) puts("I love you my love and our love save us!");
		else puts("Light my fire!");
	}	
	return 0;
} 
