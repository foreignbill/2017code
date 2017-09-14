#include <bits/stdc++.h>

#define LL long long

using namespace std;

LL fac[100];

bool v[111];

int n;

LL ans;

void dfs(int dep,int sum){
	if(sum!=0&&sum%3==0){
		ans += fac[n+1-dep];
		return;
	}
	if(dep==n+1) return;
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		dfs(dep+1,sum+i);
		v[i]=0;
	}
}

int main(){
	fac[0]=0;
	fac[1]=4;
	fac[2]=14;
	for(LL i=3;i<=15;i++){
		fac[i]=fac[i-1]*3+2*fac[i-2]+fac[i-3];
	}
	while(cin>>n){
		double ans = 1.0 / fac[n];
		printf("%.9lf\n",ans);
	}
	return 0;
} 
