#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e7+5;
bool p[maxn];
int prime[maxn/5],top;
int phi[maxn];

void init(){
	memset(p,0,sizeof p);
	top=0;
	phi[1]=1;
	for(int i=2;i<maxn;i++){
		if(!p[i]){
			prime[++top]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=top;j++){
			if(i*prime[j]>=maxn) break; 
			p[i*prime[j]]=1;
			if(i % prime[j] == 0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
}

inline ll power(ll a,ll n,ll mod){
	if(!n) return 1ll;
	ll ret=power(a,n/2,mod);
	ret = ret*ret%mod;
	if(n&1) return ret*a%mod;
	return ret;
}

inline ll solve(ll p){
	if(p==1) return 0;
	ll _phi=phi[p];
	if(p%2)
		return power(2ll,solve(_phi),p);//gcd(2,p)=1
	else
		return power(2ll,solve(_phi)+_phi,p);//gcd(2,p)=2
}

int main(){
	init();
	int T;ll p;
	for(scanf("%d",&T);T--;){
		scanf("%lld",&p);
		printf("%lld\n",solve(p));
	}
	return 0;
} 
