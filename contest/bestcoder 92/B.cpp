#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> e1[100005],e2[100005];
bool v1[100005],v2[100005];

long long ans;

void dfs(int id,int tp,int dep){
	if(dep==4){
		ans++;
		return;
	}
	if(tp==1){
		for(int i=0;i<e1[id].size();i++){
			if(v2[ e1[id][i] ]) continue;
			v2[ e1[id][i] ] = 1;
			dfs(e1[id][i],2,dep+1);
			v2[ e1[id][i] ] = 0;
		}
	}
	else if(tp==2){
		for(int i=0;i<e2[id].size();i++){
			if(v1[ e2[id][i] ]) continue;
			v1[ e2[id][i] ] = 1;
			dfs(e2[id][i],1,dep+1);
			v1[ e2[id][i] ] = 0;
		}
	}
}

int main(){
	freopen("input.txt","r",stdin);
	int T,n,m,k,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++) e1[i].clear();
		for(int i=1;i<=m;i++) e2[i].clear();
		for(int i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			e1[x].push_back(y);
			e2[y].push_back(x);
		}
		ans = 0;
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(int i=1;i<=n;i++){
			v1[i]=1;
			dfs(i,1,1);//1 is boy sheep
			v1[i]=0;
		}
		for(int i=1;i<=m;i++){
			v2[i]=1;
			dfs(i,2,1);//2 is girl sheep
			v2[i]=0;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
