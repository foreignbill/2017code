#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ans;

void dfs(ll n,ll k){
	if(!n) return;
	ans ^= n;
	ll cnt = 0,num = 0,tmp = 0;
	while(cnt <= (n-1) / k){
		tmp = cnt;
		cnt = cnt * k + 1;
		if(num == 0) num = 1;
		else num *= k;
	}
	ll pos = n - cnt;
	if(!pos) return;
	ll a = (pos + num - 1) / num;
	if(!(pos%num)){
		if(a&1) ans ^= cnt;
		if((num-a)&1) ans ^= tmp;
	} else {
		if((a-1)&1) ans ^= cnt;
		if((num-a)&1) ans ^= tmp;
		dfs(tmp + (pos % num),k);
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		ll n,k;
		scanf("%lld%lld",&n,&k);
		if(k==1) {
			if(n % 4 == 0) printf("%lld\n",n); 
			if(n % 4 == 1) printf("%lld\n",1);
			if(n % 4 == 2) printf("%lld\n",n+1);
			if(n % 4 == 3) printf("%lld\n",0);
			continue;
		} 
		ans = 0;
		dfs(n,k);
		printf("%lld\n",ans);
	}
	return 0;
} 
