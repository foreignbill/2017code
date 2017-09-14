#include <bits/stdc++.h>

#define LL long long
 
using namespace std;

LL a,b,n;
LL B;

LL pow(LL a,LL n){
	if(n==1) return 1LL;
	LL tmp=pow(a,n/2);
	if(tmp<0) tmp+=B;
	if(n&1)
		return tmp*tmp*a%B;
	return tmp*tmp%B;
}

int main(){
    while(~scanf("%lld%lld%lld",&a,&b,&n)){
    	B=b;
	    unsigned LL ans=(unsigned LL)(a * pow(10,n-1));
	    double t = ans * 1.0 / b;
	    t*=10;
	    LL TT=(LL)t;
	    TT%=10;
	    printf("%lld\n",TT);
	}
    return 0;
}
