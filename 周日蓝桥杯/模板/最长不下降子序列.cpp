#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n,a[100],dp[100]={0};
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		int Max=0;
		for(int j=1;j<i;j++)
			if(a[j]<=a[i])
				if(dp[j]>Max) Max=dp[j];
		dp[i]=Max+1;
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
} 
