#include<bits/stdc++.h>
#define maxn 4001000
#define lc (ch[o][0])
#define rc (ch[o][1])
using namespace std;
bool rev[maxn];
int cnt[maxn];
int ch[maxn][2];
int rt,tot;
int build(int dep)
{
    int now=tot++;
    if(dep>=0)
    {
        ch[now][0]=build(dep-1);
        ch[now][1]=build(dep-1);
    }
    return now;
}
void up(int o)
{
    cnt[o]=min(cnt[lc],cnt[rc]);
}
void insert(int o,int dep,int x)
{
    if(dep==-1)
    {
        cnt[o]++;
        return;
    }
    int t=(x>>dep&1);
    insert(ch[o][t],dep-1,x);
    up(o);
}
void query()
{
    int ans=0;
    int now=rt;
    for(int i=19;i>=0;--i)
    {
        if(rev[i])
        {
            if(cnt[ch[now][1]]==0)
            {
                now=ch[now][1];
            }
            else
            {
                now=ch[now][0];
                ans+=(1<<i);
            }
        }
        else
        {
            if(cnt[ch[now][0]]==0)
            {
                now=ch[now][0];
            }
            else
            {
                now=ch[now][1];
                ans+=(1<<i);
            }
        }
    }
    printf("%d\n",ans);
}
int n,m;
int main()
{
    rt=build(19);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        insert(rt,19,x);
    }
    while(m--)
    {
        int x;
        scanf("%d",&x);
        for(int i=19;i>=0;--i)
        {
            if(x>>i&1)
            {
                rev[i]^=1;
            }
        }
        query();
    }
    return 0;
}
