//https://cn.vjudge.net/contest/159928#problem/E

#include <cstdio>
#include <cstring>
#include <iostream>

#define LL long long

using namespace std;

const int maxn = 10010000;

bool isprime[maxn];
LL prime[maxn/10];

LL f[maxn];

const LL MOD = 1e9+7;

void print_prime(){
	memset(isprime,0,sizeof(isprime));
	isprime[0]=isprime[1]=1;
	prime[0]=0;
	for(LL i=2;i<maxn;i++){
		if(!isprime[i]){
			prime[++prime[0]]=i;
		}
		for(LL j=1;j<=prime[i],prime[j]*i<maxn;j++){
			isprime[prime[j]*i]=1;
			if( i % prime[j] == 0){
				break;
			}
		}
	}
}

LL pow(LL a,LL n){
	if(n==0) return 1LL;
	LL ans = pow(a,n/2);
	ans = ans * ans % MOD;
	if(n&1) return ans * a % MOD;
	return ans;
}

int main(){
	print_prime();
	LL T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		LL mn = min(n,m);
		LL ans = 1;
		for(LL i = 1;i <= prime[0] && prime[i] <= mn;i++){
			LL cnt = 0;
			for(LL d = prime[i]; d<=mn ; d*=prime[i])
				cnt += (n/d)*(m/d);
			ans = ans * pow(prime[i],cnt) % MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}
