#include <cstdio>
#include <cstring>
#include <iostream>

#define LL long long

using namespace std;

const LL MOD = 1e9 + 7;

LL pow(LL a,LL n){
	LL res = 1LL;
	for(int i=1;i<=n;i++) res = res * a % MOD;
	return res; 
}

int main(){
	int T;
	cin>>T;
	LL n,k,ans;
	while(T--){
		ans = 0;
		cin>>n>>k;
		for(LL i=1;i<=n;i++)
			ans = (ans + pow(i,k) )% MOD;
		cout<<ans<<endl;
	}
	return 0;
} 
