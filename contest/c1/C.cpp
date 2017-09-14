
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("1.in", "r", stdin)
#define OUT freopen("1.out", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

typedef pair<int,int> pii;
const int maxn=200005;
int du[maxn],e[maxn][2];
pii s[maxn];
vector<pii> g[maxn];
LL sum[maxn];
int n,m;

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)g[i].clear(),s[i]=mp(0,0),du[i]=0;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            sum[i]=0;
            scanf("%d%d",&x,&y);
            du[x]++;du[y]++;
            e[i][0]=x;e[i][1]=y;
        }
        for(int i=1;i<=m;i++)
        {
            int x=e[i][0],y=e[i][1];
            if(du[x]<du[y] || (du[x]==du[y] && x<y))g[x].pb(mp(y,i));else g[y].pb(mp(x,i));
        }
        LL ans=0;
        for(int i=1;i<=m;i++)
        {
            int x=e[i][0],y=e[i][1];
            for(auto p : g[x])s[p.first]=mp(i,p.second);
            for(auto p : g[y])
                if(s[p.first].first==i)
                {
                    sum[i]++;
                    sum[s[p.first].second]++;
                    sum[p.second]++;
                }
        }
        for(int i=1;i<=m;i++)
            ans+=(sum[i]*(sum[i]-1))>>1;
        printf("%lld\n",ans);
    }
    return 0;
}
