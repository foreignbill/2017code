#include<bits/stdc++.h>

#define OPENSTACK

using namespace std;

struct trie
{
    int num;
    struct node
    {
        int ls,rs,sum;
        void cle(){ls=rs=sum=0;}
    }tr[3050005];
    int temp[30];

    void init()
    {
        for(int i=0;i<=num;i++)tr[i].cle();
        num=0;
    }

    void add(int x)
    {
        for(int i=29;i>=0;i--)
        {
            temp[i]=x&1;
            x>>=1;
        }
        int now=0;tr[0].sum++;
        for(int i=0;i<30;i++)
        {
            if(temp[i])
            {
                if(tr[now].rs==0)tr[now].rs=++num;
                now=tr[now].rs;tr[now].sum++;
            }else
            {
                if(tr[now].ls==0)tr[now].ls=++num;
                now=tr[now].ls;tr[now].sum++;
            }
        }
    }

    void del(int x)
    {
        for(int i=29;i>=0;i--)
        {
            temp[i]=x&1;
            x>>=1;
        }
        int now=0;tr[0].sum++;
        for(int i=0;i<30;i++)
        {
            if(temp[i])
            {
                now=tr[now].rs;tr[now].sum--;
            }else
            {
                now=tr[now].ls;tr[now].sum--;
            }
        }
    }

    int query(int x)
    {
        for(int i=29;i>=0;i--)
        {
            temp[i]=x&1;
            x>>=1;
        }
        int ret=0,now=0;
        for(int i=0;i<30;i++)
        {
            if(temp[i])
            {
                if(tr[now].ls>0 && tr[tr[now].ls].sum>0)
                {
                    ret+=(1<<(29-i));
                    now=tr[now].ls;
                }else now=tr[now].rs;
                if(now==0)break;
            }else
            {
                if(tr[now].rs>0 && tr[tr[now].rs].sum>0)
                {
                    ret+=(1<<(29-i));
                    now=tr[now].rs;
                }else now=tr[now].ls;
                if(now==0)break;
            }
        }
        return ret;
    }
}tr;

const int maxn=100005;

int sz[maxn],n,q,ans[maxn],a[maxn];
vector< pair<int,int> > qu[maxn];
vector<int> g[maxn];

void cal_sz(int v,int p)
{
    sz[v]=1;
    for(auto x : g[v])
    {
        if(x!=p)
        {
            cal_sz(x,v);
            sz[v]+=sz[x];
        }
    }
}

bool big[maxn];

void add(int v,int p,int x)
{
    if(x>0)tr.add(a[v]);else tr.del(a[v]);
    for(auto u : g[v])
    {
        if(u!=p && !big[u])
            add(u,v,x);
    }
}

void DFS(int v,int p,bool k)
{
    int bn=-1;
    for(auto u : g[v])
    {
        if(u!=p)
        {
            if(bn==-1 || sz[u]>sz[bn])bn=u;
        }
    }
    for(auto u : g[v])
    {
        if(u!=p && u!=bn)
            DFS(u,v,false);
    }
    if(bn!=-1)
    {
        DFS(bn,v,true);
        big[bn]=true;
    }
    add(v,p,1);
    for( pair<int,int> p : qu[v])
    {
        ans[p.second]=tr.query(p.first);
    }
    if(bn!=-1)big[bn]=false;
    if(!k)add(v,p,-1);
}

int main()
{
#ifdef OPENSTACK
		int size = 70 << 20; // 256MB
		char *p = (char*)malloc(size) + size;
		#if (defined _WIN64) or (defined __unix)
			__asm__("movq %0, %%rsp\n" :: "r"(p));
		#else
			__asm__("movl %0, %%esp\n" :: "r"(p));
		#endif
	#endif     
    //freopen("test.in","r",stdin);
    //freopen("test.ans","w",stdout);
    while(scanf("%d%d",&n,&q)==2)
    {
        tr.init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)g[i].clear(),qu[i].clear();
        for(int i=2;i<=n;i++)
        {
            int x;scanf("%d",&x);
            g[x].push_back(i);
        }
        for(int i=1;i<=n;i++)sz[i]=0,big[i]=false;
        for(int i=1;i<=q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            qu[x].push_back(make_pair(y,i));
        }
        cal_sz(1,-1);
        DFS(1,-1,0);
        for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    }
    #ifdef OPENSTACK
		exit(0);
	#else
		return 0;
	#endif
}
