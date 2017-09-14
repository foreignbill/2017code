#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
	ll n,k;
	while(~scanf("%lld%lld",&n,&k)){
		ll res=(n-k+1)*k;
		printf("%lld\n",res);	
	}
	return 0;
} 
