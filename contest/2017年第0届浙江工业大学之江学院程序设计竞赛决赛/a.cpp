#include <bits/stdc++.h>

#define LL long long 

using namespace std;

LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}

LL lcm(LL a,LL b){
	LL ans;
	ans=a/gcd(a,b);
	LL tmp=LONG_LONG_MAX/ans;
	if (tmp<b) ans=-1;
	else ans*=b;
	return ans;
}
int main(){
	LL l,r,x,y,z,n,ans;
	while(~scanf("%lld%lld%lld%lld",&x,&y,&z,&n)){
		l=0;
		r=LONG_LONG_MAX;
		while(l+1<r){
			LL mid=(l+r)/2;
			ans=mid/x+mid/y+mid/z;
			LL t1=lcm(x,y);
			LL t2=lcm(y,z);
			LL t3=lcm(z,x);
			ans -=  mid/t1 + mid/t2 + mid/t3;
			LL t=lcm(t1,z);
			if (t!=-1) ans+=mid/t;
			if (mid-ans>=n) r=mid;
			else l=mid;
		}
		printf("%lld\n",r);
	}
	return 0;
}
