#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct Node{
    int h;
    int v;
} node[1005];

int main(){
    int t,n,m,l;
    int dp[1005];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int i;
        for(i = 1; i<=n; i++)
            scanf("%d",&node[i].h);
        for(i = 1; i<=n; i++)
            scanf("%d",&node[i].v);
        memset(dp,0,sizeof(dp));
        for(i = 1; i<=n; i++){
            for(l = m; l>=node[i].v; l--)
                dp[l] = max(dp[l],dp[l-node[i].v]+node[i].h);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}

