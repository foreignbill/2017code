#include <bits/stdc++.h> 
using namespace std;
const int MAXN = 200010;
struct Edge{
    int to,next;
}edge[MAXN*2];
int head[MAXN],tot;

int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
int n;

void init(){
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v){
    edge[tot].to = v;edge[tot].next = head[u];head[u] = tot++;
}
void dfs1(int u,int pre,int d){
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for(int i = head[u];i != -1; i = edge[i].next){
        int v = edge[i].to;
        if(v != pre){
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void getpos(int u,int sp){
    top[u] = sp;
    if(son[u] != -1){
        p[u] = pos++;
        fp[p[u]] = u;
        getpos(son[u],sp);
    } else {
        p[u] = pos++;
        fp[p[u]] = u;
        return;
    }
    //更新其他的节点
    for(int i = head[u] ; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])
            getpos(v,v);
    }
}
typedef long long  ll;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
ll MAX[MAXN<<2];
ll val[MAXN<<2];
ll MIN[MAXN<<2];
ll sum[MAXN<<2];

void pushup(int rt){
    MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
    MIN[rt]=min(MIN[rt<<1],MIN[rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void build(int l,int r,int rt){
    if(l==r){
        MAX[rt]=MIN[rt]=sum[rt]=val[fp[l]];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

ll query(ll x,ll y,int L,int R,int l,int r,int rt){
    if(l>=L&&r<=R){
        if(MAX[rt]<x||MIN[rt]>y){
            return 0;
        }
        if(MIN[rt]>=x&&MAX[rt]<=y){
            return sum[rt];
        }
    }
    int m=(l+r)>>1;
    ll res=0;
    if(m>=L)
        res+=query(x,y,L,R,lson);
    if(R>m)
        res+=query(x,y,L,R,rson);
    return res;
}

ll solve(int u,int v,ll x,ll y){
    int f1=top[u],f2=top[v];
    ll temp=0;
    while(f1!=f2){
        if(deep[f1]<deep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        temp+=query(x,y,p[f1],p[u],1,n,1);
        u=fa[f1];f1=top[u];
    }
    if(deep[u]>deep[v])
        swap(u,v);
    return (ll)temp+query(x,y,p[u],p[v],1,n,1);
}
int main(){
    int q;
    while(scanf("%d%d",&n,&q)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            scanf("%lld",&val[i]);
        }
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        build(1,n,1);
        for(int i=1;i<=q;i++){
            int u,v;
            long long x,y;
            scanf("%d%d%lld%lld",&u,&v,&x,&y);
            printf("%lld%c",solve(u, v, x, y)," \n"[i==q]);
        }
    }
    return 0;
}
