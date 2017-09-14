#include<bits/stdc++.h>
using namespace std;
#define N 1000005
bitset<N*2> bt;
const int zero=1000002;
int n,k;
int a[1005];
char b[1005][2];
void solve()
{
    bt.reset();
    bt.set(zero);
    scanf("%d%d",&n,&k);
    int sum1=0,sum2=0;
    for(int i=1; i<=n; i++) scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",b[i]);
        if(b[i][0]=='L') sum1+=a[i];
        else if(b[i][0]=='D') sum2-=a[i];
        else sum1+=a[i],sum2-=a[i];
    }
    if(sum1<k||sum2>k){ puts("no");return ;}
    for(int i=1; i<=n; i++)
    {
        if(b[i][0]=='L') bt=bt|(bt<<a[i]);
        else if(b[i][0]=='D')  bt=bt|(bt>>a[i]);
        else bt=bt|(bt>>a[i])|(bt<<a[i]);
        if(bt[k+zero]&1) break;
    }
    puts(bt[k+zero]==1? "yes":"no");
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}
