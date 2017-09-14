#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1000005];
ll sum[2000005],n;
ll sum2[2000005],x,y;
int main(){
	scanf("%I64d%I64d%I64d",&n,&x,&y);
	ll m=0;
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%I64d",&x);
		m=max(m,x);
		sum[x]++;
		sum2[x]+=x;
	}
	m++;
	for(int i=1;i<=2000000;i++){
		sum[i]+=sum[i-1];
		sum2[i]+=sum2[i-1];
	}
	ll res = LONG_LONG_MAX;
	for(ll gcd=2;gcd<=1000000;gcd++){
		ll cost=0;
		for(ll k=0;k*gcd+1<=m;k++){
			ll l=k*gcd+1,r=(k+1)*gcd-1;
			if(y*(gcd-1)<=x){
				cost += (ll)((ll)(k+1ll)*gcd*(sum[r]-sum[l-1])-sum2[r]+sum2[l-1])*y;
			} else if(y>=x){
				cost += (ll)((ll)sum[r]-sum[l-1])*x;
			} else {
				ll t = x/y;
				int l1,r1;
				l1 = (k+1ll)*gcd-t;
				r1 = l1-1;
				cost += (ll)((ll)(k+1ll)*gcd*(sum[r]-sum[l1-1])-sum2[r]+sum2[l1-1])*y;
				cost += (ll)((ll)sum[r1]-sum[l-1])*x;
			}
		}
		res = min(res,cost);
	}
	printf("%I64d\n",res);
	return 0;
} 
