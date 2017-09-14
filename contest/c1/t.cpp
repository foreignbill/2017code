#include <bits/stdc++.h>
#define rep(i,s,t) for (int i=s;i<=t;++i)
const int maxn=550;

using namespace std;
int matching[maxn];
int check[maxn];
int g[maxn][maxn];
int n,m;
bool dfs(int u,int x)
{
    rep(v,1,m)
    {
        if (g[u][v]>=x)
            if (!check[v])
            {
                check[v] = true;
                if (matching[v] == -1 || dfs(matching[v],x))
                {
                    matching[v] = u;
                    return true;
                }
            }
    }
    return false;
}

int hungarian(int x)
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    rep(i,1,n)
    {
        memset(check, 0, sizeof(check));
        if (dfs(i,x))
            ++ans;
    }
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        rep(i,1,n)
        {
            rep(j,1,m)
            {
                scanf("%d",&g[i][j]);
            }
        }
        int l=0,r=1000,ans=0;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            if (hungarian(mid)>=n) l=mid+1,ans=mid;
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
