#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p,a;//x^3=a (% p)
inline ll power(ll a,ll n,int p){
	ll ret=1;ll now=a;
	while(n!=0){
		if(n&1)
			ret=ret*now%p;
		now=now*now%p;
		n>>=1;
	}
	return ret;
}
struct node{
	ll x,y,z;
	node operator * (const node & t){
		return node{
			(x*t.x+(y*t.z+z*t.y)%p*a)%p,
			(x*t.y+y*t.x+z*t.z%p*a)%p,
			(x*t.z+y*t.y+z*t.x)%p
		};
	}
};
inline node power(node a,ll n,int p){
	if(!n) return node{1,0,0};
	node ret=power(a,n/2,p);
	ret=ret*ret; 
	if(n&1){
		ret=ret*a;
		return ret;
	}
	return ret;
}

ll Legendre(ll a,ll p){
	return power(a,(p-1)>>1,p);
}

struct _node{
	ll p,d;
};

_node mul(_node A,_node B,ll p,ll w){
	_node res;
	res.p=(A.p*B.p%p+A.d*B.d%p*w%p)%p;
	res.d=(A.p*B.d%p+A.d*B.p%p)%p;
	return res;
}

_node _power(_node a,ll n,ll p,ll w){
	if(!n) return _node{1,0};
	_node ret=_power(a,n/2,p,w);
	ret=mul(ret,ret,p,w);
	if(n&1) return mul(ret,a,p,w);
	return ret;
}

ll rando(){
	return (ll)rand() << 15 | rand();
}

ll solve(ll n,ll p){
	if(p==2) return 1;
	if(Legendre(n,p)+1==p) return -1;
	ll a,t;
	ll w;
	while(1){
		a=rand()%p;
		t=a*a-n;
		w=(t%p+p)%p;
		if(Legendre(w,p)+1==p) break;
	}
	_node res={a,1};
	res=_power(res,(p+1)>>1,p,w);
	return res.p;
}

int main(){
	srand((unsigned)time(0));
	int T;scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&p,&a);
		if(!a || p<=3){
			printf("%lld\n",a);
			continue;
		}
		if(p%3!=1){
			printf("%lld\n",power(a,(p+p-1)/3,p));
			continue;
		}
		if(power(a,(p-1)/3,p)!=1){
			puts("No Solution");
			continue;
		}
		node ret;
		while(1){
			ret.x=rando()%p;
			ret.y=rando()%p;
			ret.z=rando()%p;
			ret=power(ret,(p-1)/3,p);
			if(ret.x==0&&ret.z==0) break;
		}
		ll res=(solve(p-3,p)-1)*((p+1)/2)%p;
		ll ans[3];
		ans[0]=power(ret.y,p-2,p);
		ans[1]=ans[0]*res%p;
		ans[2]=ans[1]*res%p;
		sort(ans,ans+3);
		for(int i=0;i<3;i++)
			printf("%lld%c",ans[i]," \n"[i==2]);
	}
	return 0;
}
