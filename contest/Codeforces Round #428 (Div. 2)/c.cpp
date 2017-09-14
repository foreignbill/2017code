#include <bits/stdc++.h>

using namespace std;

vector<int> e[100005];
int du[100005];
int n,u,v;

double ans;

void dfs(int id,double eps,int fa,int dep){
	for(auto ed:e[id]){
		if(ed == fa) continue;
		if(du[ed] == 1){
			ans += eps*(dep+1);
		}
		dfs(ed,eps*1.0/(du[ed]-1),id,dep+1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		du[u]++;du[v]++;
	}
	ans = 0;
	dfs(1,1.0/du[1],0,0);
	printf("%.12lf\n",ans);
	return 0;
} 
