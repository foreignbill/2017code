#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
typedef long long ll;
int n,q,top;
int prime[1000005];
int Next[1000005];//n的最大质因子 
bool p[1000005];
int sum[1000005];

void init(int n){
	top=0;
	memset(p,0,sizeof p);
	for(int i=2;i<=n;i++){
		if(!p[i]){
			prime[++top]=i;
			Next[i]=top;
		}
		for(int j=1;j<=top && i*prime[j]<=n;j++){
			p[i*prime[j]]=1;
			Next[i*prime[j]]=j;
			if(i%prime[j]==0){
				break;
			}
		}
	}
}

void solve(int n){
	while(n!=1){
		sum[Next[n]]++;
		n/=prime[Next[n]];
	}
}

int main(){
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;i++)
		solve(i);
	ll res=1;
	for(int i=1;i<=top;i++){
		res *= (ll)(sum[i]*2ll+1ll);
		res %= mod;
	}
	printf("%lld\n",res);
	return 0; 
}
