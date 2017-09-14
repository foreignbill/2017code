#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int MAXN = 1e6+5;
const int N = 1e6;
int cnt[MAXN],tot[MAXN],sum[MAXN],ans[MAXN];
void init(){
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			cnt[j]++;
	tot[1]=sum[1]=1;
	ans[1]=1;
	for(int i=2;i<=N;i++){
		tot[i] = tot[i-1] + cnt[i-1] + 1;tot[i] %= MOD;
		sum[i] = tot[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=i+i;j<=N;j+=i){
			sum[j] -= sum[i];
			sum[j] = (sum[j] % MOD + MOD) % MOD;
		}
	}
	for(int i=2;i<=N;i++)
		ans[i] = (ans[i-1] + sum[i]) % MOD;
}

int main(){
	init();
	for(int n;~scanf("%d",&n);) printf("%d\n",ans[n]); 
	return 0;
} 
