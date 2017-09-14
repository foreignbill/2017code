#include <bits/stdc++.h>

using namespace std;

int n;
int a[100];
bool v[100];

void dfs(int dep){
	if(dep==1+n){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		a[dep]=i;
		dfs(dep+1);
		v[i]=0;
	}
}

int main(){
	while(~scanf("%d",&n)){
		memset(v,0,sizeof v);
		dfs(1);	
	}
	return 0;
} 
