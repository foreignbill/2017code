#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll m,n,k;
ll f[1000005];
ll res[1000005];

const ll MOD = 1e9+7;

ll ans;

ll sqsigma(ll n){
	ll tmp = n*(n+1)*(n+n+1)/6;
	return tmp * tmp;
}

int main(){
	ll i,j,T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>m>>n;
		k=min(m,n);
		memset(f,0,sizeof(f)); 
		for(i=k;i;i--){
			f[i]=(ll)(m/i)*(n/i);
			for(j=2;j*i<=k;j++){
				f[i]-=f[i*j];
				res[i]+=res[i*j];
			}
			ans += ( sqsigma(n/i) * sqsigma(m/i) - res[i] ) * f[i];
			res[i] += sqsigma(n/i) * sqsigma(m/i) - res[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}
