#include <iostream>  
#include <algorithm>  
#include <cstring>  
#define inf 0x3f3f3f3f3f3f3f3f  
  
using namespace std;  
  
struct node  
{  
    long long cost,wei;  
    bool operator<(struct node &T) const  
    {  
        return wei<T.wei;  
    }  
}e[3005];  
  
int n;  
long long dp[3005][3005];  

int main(){
    while(cin>>n){ 
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)
            cin>>e[i].wei>>e[i].cost;
        sort(e+1,e+1+n);
        dp[1][1]=e[1].cost;
        for(int i=2;i<=n;i++)  
        {
            for(int j=1;j<i;j++)  
            {
                if(dp[i-1][j]<inf)
                    dp[i][j]=dp[i-1][j]+e[i].wei-e[j].wei;
                dp[i][i]=min(dp[i][i],dp[i-1][j]);
            }
            dp[i][i]+=e[i].cost;
        }
        cout<<*min_element(dp[n]+1,dp[n]+1+n)<<endl;
    }
    return 0;
}
