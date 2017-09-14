#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define clr(x,y) memset(x,y,sizeof x)

using namespace std;

const int maxn=200005;
struct Edge
{
    int to,next;
} edge[maxn*2];

int cnt,head[maxn];
int pre[maxn][50],fgcd[100],f[maxn],tot,res[maxn];

int gcd(int a,int b)
{
    if (b==0) return a;
    else
        return gcd(b, a % b);
}

void init()
{
    tot=0;
    cnt=0;
    memset(res,-inf,sizeof res);
    memset(head,-1,sizeof head);
}
void add(int u,int v)
{
    edge[tot].to=v;
    edge[tot].next=head[u];
    head[u]=tot++;
}

void dfs(int u,int fa,int tgcd)
{
    int save;
    save=cnt;
    for (int i=0; i<cnt; i++)
    {
        pre[u][i] = fgcd[i];
        fgcd[i] = gcd(fgcd[i], f[u]);
        res[u] = max(res[u],fgcd[i]);
    }

    fgcd[cnt++] = tgcd;

    res[u] = max(res[u],tgcd);

    sort(fgcd,fgcd+cnt);

    cnt=unique(fgcd,fgcd+cnt) - fgcd;

    tgcd=gcd(tgcd,f[u]);

    res[u] = max(res[u],tgcd);

    for (int i=head[u]; ~i; i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fa) continue;
        dfs(v,u,tgcd);
    }
    cnt=save;
    for (int i=0; i<cnt; i++)
        fgcd[i]=pre[u][i];
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d",&f[i]);
    init();
    int u,v;
    for (int i=1; i<n; i++)
    {
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,-1,0);
    for (int i=1; i<=n; i++)
        printf("%d%c",res[i],i==n?'\n':' ');
    return 0;
}
