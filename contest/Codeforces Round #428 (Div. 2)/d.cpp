#include <iostream>
#include <cstdio>
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
using namespace std;
typedef long long ll;
const int Maxn = 1e6+10;
const int Mod = 1e9+7;
ll a[Maxn];
ll b[Maxn],prime[Maxn];
int n,z;
int main() {
	cin >> n;
	for(int i=1;i<=n;i++)
		scanf("%d",&z),a[z]++;
	ll ans=0,x=1;
	lpi(i,0,1e6)b[i]=x,x = (x*2) % Mod;
	lpi(i,2,1e6)prime[i] = i;
	lpi(i,2,1e6)for (int j=i+i; j<=1e6; j+=i)
			prime[j]-= prime[i];
	for (ll i=2; i<=1e6; i++) {
		ll cnt=0;
		for (int j=i; j<=1e6; j+=i)
			cnt+=a[j];
		if (cnt==0) continue;
		ans+=(cnt*prime[i])% Mod *b[cnt-1]%Mod;
		ans %= Mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
