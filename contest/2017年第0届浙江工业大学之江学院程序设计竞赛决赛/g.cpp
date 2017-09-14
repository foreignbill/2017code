#include <bits/stdc++.h>

#define LL long long

using namespace std;

const LL MOD = 1e9+7;

int T;
LL n;

LL pow(LL a,LL n){
	if(n==0) return 1LL;
	LL tmp=pow(a,n/2);
	if(n&1) return tmp*tmp*a%MOD;
	return tmp*tmp%MOD;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<=4){
			printf("%d\n",n);
			continue;
		}
		LL t = n/3;
		LL p = n%3;
		LL ans;
		if(p==1) ans=pow(3LL,t-1)*4LL%MOD;
		if(p==2) ans=pow(3LL,t)*2LL%MOD;
		if(p==0) ans=pow(3LL,t);
		printf("%lld\n",ans);
	} 
	return 0;
}
