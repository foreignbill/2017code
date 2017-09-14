#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline ll power(ll a,ll n,ll p){
	if(!n) return 1;
	ll ret=power(a,n/2,p);
	ret=ret*ret%p;
	if(n&1) return ret*a%p;
	return ret;
}

ll Legendre(ll a,ll p){
	return power(a,(p-1)>>1,p);
}

struct node{
	ll p,d;
};

node mul(node A,node B,ll p,ll w){
	node res;
	res.p=(A.p*B.p%p+A.d*B.d%p*w%p)%p;
	res.d=(A.p*B.d%p+A.d*B.p%p)%p;
	return res;
} 

node _power(node a,ll n,ll p,ll w){
	if(!n) return node{1,0};
	node ret=_power(a,n/2,p,w);
	ret=mul(ret,ret,p,w);
	if(n&1) return mul(ret,a,p,w);
	return ret;
}

ll solve(ll n,ll p){
	if(p==2&&n<p) return 1;
	if(Legendre(n,p)+1==p) return -1;
	ll a,t;
	ll w;
	while(1){
		a=rand()%p;
		t=a*a-n;
		w=(t%p+p)%p;
		if(Legendre(w,p)+1==p) break;
	}
	node res={a,1};
	res=_power(res,(p+1)>>1,p,w);
	return res.p;
}

int main(){
	srand((unsigned)time(0));
	ll n,p;
	while(~scanf("%lld%lld",&p,&n)){
		n %= p;
		ll res=solve(n,p);
		if(res==-1){
			puts("No Solution");
			continue;
		}
		ll res2=p-res;
		if(res>res2) swap(res,res2);
		if(res==res2)
			printf("%lld\n",res);
		else printf("%lld %lld\n",res,res2);
	}
	return 0;
}
