#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int n,m,start,end,Maxdep,x;

vector<int> e[20005];

bool v[20005];

void dfs(int id,int dep){
	if(dep>Maxdep){
		Maxdep=dep;
		start=id;
	}
	for(int i=0;i<e[id].size();i++){
		int now = e[id][i];
		if(v[now]) continue;
		v[now]=1;
		dfs(now,dep+1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		e[x].push_back(i);
		e[i].push_back(x);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		e[x].push_back(i+n);
		e[i+n].push_back(x);
	}
	start=0;
	Maxdep=0;
	memset(v,0,sizeof(v));
	v[1]=1;
	dfs(1,1);
	memset(v,0,sizeof(v));
	v[start]=1;
	dfs(start,1);
	printf("%d\n",Maxdep-1);
	return 0;
} 
