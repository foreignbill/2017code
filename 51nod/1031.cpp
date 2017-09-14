#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
typedef long long ll;
int f[1005];

int main(){
	int n;
	scanf("%d",&n);
	f[1]=1;f[2]=2;
	for(int i=3;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	printf("%d\n",f[n]);
	return 0;
} 
