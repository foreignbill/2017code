#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n,m;

const LL MOD = 1e9+7;

LL f[55][55];

LL dfs(int n,int m){
	if(n<m) return 0;
	if(f[n][m]) return f[n][m];
	if(m==0) return 1LL;
	if(n==1 && m==1) return 1LL;
	LL tmp=0;
	for(int left=0;left<=n-1;left++)
		for(int i=0;i<=left&&i<=m;i++){
			LL tmp1=dfs(left,i);
			LL tmp2=dfs(n-left-1,m-i);
			tmp = (tmp + tmp1*tmp2 % MOD)%MOD;
		}
	f[n][m]=tmp;
	return tmp;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		LL ans = dfs(n,m);
		printf("%d\n",ans);
	}
	return 0;
} 
