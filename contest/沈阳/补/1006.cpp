#include <bits/stdc++.h>

using namespace std;
const int maxn = 20005;
const int base = 1000;
int S[maxn];
int dp[base<<1][2][202];//0 A 1 Bob

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		S[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",S+i),S[i]+=S[i-1];
		memset(dp,0,sizeof dp);
		for(int i=n;i>0;i--)
			for(int k=200;k>=1;k--){
				if(i+k<=n){
					dp[i%base][1][k]=min(dp[(i+k)%base][0][k]-S[i+k-1]+S[i-1],dp[(i+k+1)%base][0][k+1]-S[i+k]+S[i-1]);
					dp[i%base][0][k]=max(dp[(i+k)%base][1][k]+S[i+k-1]-S[i-1],dp[(i+k+1)%base][1][k+1]+S[i+k]-S[i-1]);
				} else if(i+k-1<=n){
					dp[i%base][1][k]=dp[(i+k)%base][0][k]-S[i+k-1]+S[i-1];
					dp[i%base][0][k]=dp[(i+k)%base][1][k]+S[i+k-1]-S[i-1];
				}
			}
		printf("%d\n",dp[1][0][1]); 
	}
	return 0;
} 
