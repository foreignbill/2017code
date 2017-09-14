#include <cstdio>

typedef long long ll;
const int maxn = 5;
ll a[maxn],m[maxn]; 

ll exgcd(ll a,ll b,ll&x,ll&y){
  if(!b)return x=1,y=0,a;
  ll d=exgcd(b,a%b,x,y),t=x;
  return x=y,y=t-a/b*y,d;
}

ll CRT(ll *a,ll *m,ll n) {
    ll ans = 0;
    ll M = 21252;
    for (int i=1;i<=n;i++) {
        ll Mi=M/m[i];
        ll t,y;
        exgcd(Mi,m[i],t,y);
        ans=(ans+a[i]*Mi*t)%M;
    }
    return ans;
}

int main(){
	m[1]=23;m[2]=28;m[3]=33;
	int cas=1,d;
	while(~scanf("%lld%lld%lld%d",a+1,a+2,a+3,&d)){
		if(a[1]==-1&&a[2]==-1&&a[3]==-1&&d==-1) break;
		ll res=CRT(a,m,3ll);
		res=(res-d)%21252;
		if(res<=0)
			res+=21252;
		printf("Case %d: the next triple peak occurs in %d days.\n",cas++,res);
	}
	return 0;
} 
