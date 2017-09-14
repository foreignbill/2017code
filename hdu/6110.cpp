#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;

struct node{
    int to,w;
    node(int to,int w):to(to),w(w){}
};

vector<node> e[maxn];
int dist[maxn],n,m,Q;
struct path{
	int a,b,c;
	path(){}
	path(int A,int B,int C) {a=A,b=B,c=C;}
}p[maxn],T[maxn<<2];

int deep[maxn],f[maxn],anc[maxn][25];

void dfs(int x,int fa){
    anc[x][0]=f[x];
    for(int i=1;i<=20;i++) anc[x][i]=anc[anc[x][i-1]][i-1];
    for(int i=0;i<e[x].size();i++){
        int next=e[x][i].to;
        if(next!=fa){
            f[next]=x;
            deep[next]=deep[x]+1;
            dist[next]=dist[x]+e[x][i].w;
            dfs(next,x);
        }
    }
}

int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    for(int i=20;i>=0;i--) if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
    if(x==y) return x;
    for(int i=20;i>=0;i--) if(anc[x][i]!=anc[y][i]) x=anc[x][i],y=anc[y][i];
    return f[x];
} 

bool cmp(int a,int b){
    return deep[a]<deep[b];
}

path mix(path x,path y){
    if(!x.c||!y.c) return path(0,0,0);
    int cs[6]; 
    cs[1]=lca(x.a,y.a);
	cs[2]=lca(x.a,y.b);
	cs[3]=lca(x.b,y.a);
	cs[4]=lca(x.b,y.b);
    sort(cs+1,cs+1+4,cmp);
    int md=max(deep[x.c],deep[y.c]),nd=min(deep[x.c],deep[y.c]);
    if(deep[cs[1]]<nd||deep[cs[3]]<md) return path(0,0,0);
    else return path(cs[3],cs[4],lca(cs[3],cs[4]));
}

void init(){
	memset(f,0,sizeof(f));
    memset(anc,0,sizeof(anc));
    memset(deep,0,sizeof(deep));
    memset(dist,0,sizeof(dist));
    deep[1]=1;
    dfs(1,0);
}

void build(int l,int r,int tp){
	if(l==r){
		T[tp]=p[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,tp<<1);
	build(mid+1,r,tp<<1|1);
	T[tp]=mix(T[tp<<1],T[tp<<1|1]);
}

path query(int l,int r,int tp,int L,int R){
    if(L<=l&&r<=R)  return T[tp];
    int mid=l+r>>1;
    if(R<=mid)  return query(l,mid,tp<<1,L,R);
    if(L>mid)   return query(mid+1,r,tp<<1|1,L,R);
    return mix(query(l,mid,tp<<1,L,R),query(mid+1,r,tp<<1|1,L,R));
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(node(v,w));
			e[v].push_back(node(u,w));
		}
		init();
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p[i].a,&p[i].b);
			p[i].c = lca(p[i].a,p[i].b);
		}
		build(1,m,1);
		scanf("%d",&Q);
		for(int i=1;i<=Q;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			path ans = query(1,m,1,a,b);
			printf("%lld\n",dist[ans.a]+dist[ans.b]-2*dist[ans.c]);
		}
	}
	return 0;
}
