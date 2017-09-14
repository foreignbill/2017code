#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,a;

ll power(ll a,ll b,ll mod){
	if(b==0) return 1ll;
	ll ret = power(a,b/2,mod);
	ret = ret * ret % mod;
	if(b&1)
		return ret*a%mod;
	return ret;
}

ll up(ll n,ll a){
	return (n + a - 1) / a;
}

int main(){
	//freopen("output.txt","w",stdout);
	while(~scanf("%lld%lld",&n,&a)){
		if(a&1){
			puts("1");
			continue;
		}
		ll mod = 1<<n;
		ll cnt2; 
		/*if(mod <= 1024){
			cnt2 = 0;
			for(ll i=1;i<=mod;i++)
				if(power(a,i,mod) == power(i,a,mod))
					cnt2++,printf("%d^%d == %d^%d\n",a,i,i,a);
			printf("%lld\n",cnt2);
		} else */{
			cnt2 = mod / 2;
			for(ll i=2;i<=1024;i+=2){
				cnt2--;
				if(power(a,i,mod) == power(i,a,mod))
					cnt2++/*,printf("%d^%d == %d^%d\n",a,i,i,a)*/;
			}
			printf("%lld\n",cnt2);
		}
		ll res = 0;
		for(int i=2;i<=n;i+=2)
			if(power(a,i,mod) == power(i,a,mod)) res++;
		res += (1<<n) >> (up(n,a));
		res -= n >> (up(n,a));
		printf("%d\n",res);
	}
	return 0;
} 
