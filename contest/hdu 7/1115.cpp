#include <cstdio> 
#include <iostream>
#include <cmath>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
const int MAXN = 30005;  
int dp[MAXN],v[MAXN],w[MAXN];  
int n,m;  

int main(){
    while(~scanf("%d%d",&n,&m)){
    	memset(dp,0,sizeof(dp));
	    for(int i = 1; i <= m; i ++)  
	        scanf("%d%d",&v[i],&w[i]);  
	    dp[0] = 0;  
	    for(int i = 1; i <= m; i ++)  
	        for(int j = n; j >= v[i]; j --)  
	            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);  
	    printf("%d\n",dp[n]); 
	}
    return 0;  
} 
