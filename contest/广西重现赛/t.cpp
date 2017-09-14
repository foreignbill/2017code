#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll powder(ll a,ll n){
	if(n==0) return 1ll;
	ll ret = powder(a,n/2);
	ret = ret * ret;
	if(n&1) return ret*a;
	return ret;
}

int main(){
	int T;
	ll n;
	while(cin>>n){
		int cnt = 0;
		for(ll i=1;i<=15;i++){
			if(powder(i,i)<=n)
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
