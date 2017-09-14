#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;
const int maxn = 1000005;
bool checked[maxn];
int prime[100005];
ll bit[100005];
int tot;
void getPrime(){
	memset(checked, 0 ,sizeof checked);
	tot = 0;
	for(int i = 2;i < maxn;i++){
		if(!checked[i]) prime[++tot] = i;
		for(int j=1;j<=tot;j++){
			if(i*prime[j]>=maxn) break;
			checked[i*prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

inline ll solve(ll a,ll k){
	if(a==1) return 1;
	ll cnt,ans = 1;
	for(int j=1;j<=tot && prime[j]*prime[j]<=a;j++){
		if(a % prime[j]) continue;
		cnt=0;
		while(a % prime[j]==0){
			a /= prime[j];
			cnt++;
		}
		ans = ans*(cnt*k+1)%MOD;
	}
	if(a>1)
		ans = (ans<<1)%MOD;
	return ans;
}

int main(){
	getPrime(); 
	int T;
	ll l,r,k;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&l,&r,&k);
		ll res = 0;
		for(ll i=l;i<=r;i++){
			res += solve(i,k);
		}
		res%=MOD;
		printf("%lld\n",res);
	}
	return 0;
}
