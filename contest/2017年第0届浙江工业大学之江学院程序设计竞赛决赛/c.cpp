#include <bits/stdc++.h>

#define LL long long

using namespace std;

LL n,m,k; 

LL C(LL n,LL m){
	LL num2=0,num5=0;
	for(LL i=2LL;i<=n;i*=2)
		num2+=n/i;
	for(LL i=5LL;i<=n;i*=5)
		num5+=n/i;
	for(LL i=2LL;i<=m;i*=2)
		num2-=m/i;
	for(LL i=5LL;i<=m;i*=5)
		num5-=m/i;
	for(LL i=2LL;i<=(n-m);i*=2)
		num2-=(n-m)/i;
	for(LL i=5LL;i<=(n-m);i*=5)
		num5-=(n-m)/i;
	return min(num2,num5);
}

int main(){
	while(~scanf("%lld%lld%lld",&n,&m,&k)){
		m-=n*k;
		if(m<0){
			puts("0");
			continue;
		}
		LL Zero=C(n+m-1,n-1);
		printf("%lld\n",Zero);
	}
	return 0;
} 
