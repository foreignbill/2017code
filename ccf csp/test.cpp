#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#define MS(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,m,degree[10005],head[10005],f;
int path[200000],vis[10005],h;
struct node
{
  int e,v,next;
}edge[200000];
struct hyf
{
    int s,e,sum;
}p[200000];
bool cmp(hyf a,hyf b)//按s大,e大排。
{
  return a.sum>b.sum;
}
void add(int s,int e)
{
    edge[f].e=e;
    edge[f].next=head[s];
    edge[f].v=0;
    head[s]=f;
    f++;
}
void dfs(int u)
{
  int i;
  vis[u]=1;
  for(i=head[u];i!=-1;i=edge[i].next)
  {
     if(!edge[i].v&&!edge[i^1].v)
     {
         edge[i].v=1;
         edge[i^1].v=1;
         dfs(edge[i].e);
     }
  }
  path[h++]=u;
}
int main()
{
    int i,a,b,ans=0,sign=0,j;
    cin>>n>>m;
    MS(degree,0);
    MS(head,-1);
     f=0;
   for(i=0;i<m;i++)
    {
      cin>>p[i].s>>p[i].e;
      p[i].sum=p[i].s+p[i].e;
      degree[p[i].s]++,degree[p[i].e]++;
    }
    sort(p,p+m,cmp);//这样排序可以使字典序最小。
    for(i=0;i<m;i++)
    {
        add(p[i].s,p[i].e);
        add(p[i].e,p[i].s);
    }
    dfs(1);
   for(i=1;i<=n;i++)
    if(!vis[i])
       sign=1;
   for(i=1;i<=n;i++)
      if(degree[i]&1)
        ans++;
   if(!(ans==0||ans==2)||sign)
       cout<<"-1\n";
   else
   {
     for(i=h-1;i>-1;i--)
        cout<<path[i]<<" ";
        cout<<endl;
   }
    return 0;
}

