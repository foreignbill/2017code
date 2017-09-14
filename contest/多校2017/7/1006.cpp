#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool v[5000];
ll f[505][505];
ll c[505][505];
const ll MOD = 1e9+7;
int ans;
void init(){
	c[0][0]=1;
	for(int i=1;i<=500;i++)
		c[i][0]=1;
	for(int i=1;i<=500;i++)
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j] + c[i-1][j-1])%MOD;
}
ll C(int now,int i){
	if(i<0 || i>now) return 0;
	return c[now][i];
}
ll dfs(int now,int k){
	if(now<0) return 0;
	if(now==0) return 1;
	if(f[now][k]) return f[now][k];
	int res = 0;
	for(int i=1;i<=k;i++){
		res += C(now,i)*dfs(now-i,k) % MOD;
		res %= MOD;
	}
	return f[now][k] = res;
}
int main(){
	int T,n,k;
	init();
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		memset(v,0,sizeof v);
		for(int i=2;i*i<=n;i++){
			for(int j=i*i;j<=n;j+=i)
				v[j]=1;
		}
		int cnt = 0;
		for(int i=1;i<=n;i++)
			if(v[i]==0) cnt++;
		memset(f,0,sizeof f);
		printf("%d\n",dfs(cnt,k));
	}
	return 0;
} 
