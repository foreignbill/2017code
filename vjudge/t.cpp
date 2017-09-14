#include <cstdio>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll a,b,p;//a^x=b(mod p)
unordered_map<ll,int> mp;
bool flag; 

inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

inline ll power(ll a,ll n,ll p){
	ll ret=1;ll now=a;
	while(n!=0){
		if(n&1)
			ret=ret*now%p;
		now=now*now%p;
		n>>=1;
	}
	return ret;
}

inline void BSGS(ll a,ll b,ll p){
	if(/*gcd(a,p)!=1*/a % p == 0){
		flag=0;
		return;
	}
	mp.clear(); 
	ll l=1,r=p;
	ll m;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(mid*mid>=p)
			r=mid-1,m=mid;
		else l=mid+1;
	} 
	
	ll tmp=b%p;
	for(int i=0;i<=m;i++){
		mp[tmp]=i;
		tmp=tmp*a%p;
	}
	tmp=power(a,m,p);
	ll ret=1;
	for(int i=1;i<=m;i++){
		ret=ret*tmp%p;
		if(mp.find(ret)!=mp.end()){
			printf("%lld\n",m*i-mp[ret]);
			flag=1;
			return;
		}
	}
}

int main(){
	while(~scanf("%lld%lld%lld",&p,&a,&b)){
		flag=0;
		BSGS(a,b,p);
		if(!flag)
			puts("no solution");
	}
	return 0;
} 
