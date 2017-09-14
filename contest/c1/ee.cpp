#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll power(ll a,ll n){
	if(n==0) return 1ll;
	ll ret = power(a,n/2);
	ret = ret*ret%MOD;
	if(n&1) return ret*a%MOD;
	return ret;
}

int main(){
	ll n;
	while(~scanf("%lld",&n)){
		ll res = power(n,6ll) + 3ll*power(n,4ll)%MOD + 12ll*power(n,3ll)%MOD + 8ll*power(n,2ll);
		res %= MOD;
		res = res * power(24ll,MOD-2) % MOD;
		printf("%lld\n",res);
	}
	return 0;
} 
