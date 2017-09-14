#include<bits/stdc++.h>
#define maxn 100050
#define inf 0x3f3f3f3f
#define mm(a,b) memset(a,b,sizeof(a))
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
using namespace std;
int n,q,step;
int c[maxn];
int sz[maxn],dep[maxn],fa[maxn],son[maxn];
int id[maxn],top[maxn];
int val[maxn];
struct T{
    int lc,rc,lazy,num;
}tree[maxn<<2];
vector<int>e[maxn];
void init(){
    for(int i=0;i<=n;i++) e[i].clear();
    mm(sz,0),mm(dep,0),mm(fa,0),mm(son,0);
    mm(id,0),mm(top,0),mm(val,0),mm(c,0);
    mm(tree,0);
    step=0;
}
void dfs1(int x,int f,int deep){
    sz[x]=1,fa[x]=f,son[x]=0,dep[x]=deep;
    int len=e[x].size();
    for(int i=0;i<len;i++){
        int next=e[x][i];
        if(next==f) continue;
        dfs1(next,x,deep+1);
        sz[x]+=sz[next];
        if(sz[son[x]]<sz[next]) son[x]=next;
    }
}
void dfs2(int x,int tp){
    top[x]=tp;
    id[x]=++step;
    val[id[x]]=x;
    if(son[x]) dfs2(son[x],tp);
    int len=e[x].size();
    for(int i=0;i<len;i++){
        int next=e[x][i];
        if(next==fa[x] || next==son[x]) continue;
        dfs2(next,next);
    }
}
T merge(T a,T b){
	if(a.num==0) return b;
	if(b.num==0) return a;
	T temp;
	temp.lc=a.lc;
	temp.rc=b.rc;
	if(a.rc==b.lc) temp.num=a.num+b.num-1;
	else temp.num=a.num+b.num;
	return temp;
}
void push_up(int rt){
    tree[rt].lc=tree[rt<<1].lc;
    tree[rt].rc=tree[rt<<1|1].rc;
    tree[rt].num=tree[rt<<1].num+tree[rt<<1|1].num;
    if(tree[rt<<1].rc==tree[rt<<1|1].lc) tree[rt].num--;
}
void push_down(int rt){
	if(tree[rt].lazy){
		tree[rt<<1].lazy=tree[rt].lazy;
		tree[rt<<1|1].lazy=tree[rt].lazy;
		tree[rt<<1].num=tree[rt<<1|1].num=1;
		tree[rt<<1].lc=tree[rt<<1].rc=tree[rt<<1|1].lc=tree[rt<<1|1].rc=tree[rt].lazy;
		tree[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	tree[rt].lazy=0;
    if(l==r){
    	tree[rt].lc=c[val[l]];
    	tree[rt].rc=c[val[l]];
    	tree[rt].num=1;
    	return;
	}
	int mid=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(rt);
}
void update(int rt,int l,int r,int L,int R,int x){
    if(l>=L && r<=R){
    	tree[rt].lazy=x;
    	tree[rt].lc=tree[rt].rc=x;
    	tree[rt].num=1;
		return;
	}
	push_down(rt);
	int mid=(l+r)>>1;
	if(mid>=R) update(lson,L,R,x);
	else if(mid<L) update(rson,L,R,x);
	else{
		update(lson,L,R,x);
		update(rson,L,R,x);
	}
	push_up(rt);
}
T query(int rt,int l,int r,int L,int R){
	if(l>=L && r<=R) return tree[rt];
	push_down(rt);
	int mid=(l+r)>>1;
	if(mid>=R) return query(lson,L,R);
	else if(mid<L) return query(rson,L,R);
	else return merge(query(lson,L,R),query(rson,L,R));
}
void change(int x,int y,int val){
	while(top[x]!=top[y]){  
        if(dep[top[x]]<dep[top[y]]) swap(x,y);  
        update(1,1,n,id[top[x]],id[x],val);  
        x=fa[top[x]];  
    }  
    if(dep[x]>dep[y]) swap(x,y);  
    update(1,1,n,id[x],id[y],val);  
}
int queryco(int x,int y){
	T l,r;
	l.lc=l.rc=l.num=l.lazy=0;
	r.lc=r.rc=r.num=r.lazy=0;
	while(top[x]!=top[y]){  
        if(dep[top[x]]<dep[top[y]]){
        	swap(x,y);
        	swap(l,r);
		}
        l=merge(query(1,1,n,id[top[x]],id[x]),l);    
        x=fa[top[x]];
    }  
    if(dep[x]>dep[y]){
    	swap(x,y);
    	swap(l,r);
	}  
    r=merge(query(1,1,n,id[x],id[y]),r);
    int ans=0;
	if(l.lc==r.lc) ans=l.num+r.num-1;
	else ans=l.num+r.num;
	return ans;
}
int main(){
//	freopen("input.txt","r",stdin);
	while(scanf("%d%d",&n,&q)!=EOF){
		init();
		for(int i=1;i<=n;i++) scanf("%d",&c[i]),c[i]++;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0,0);
		dfs2(1,1);
		build(1,1,n);
		while(q--){
			char op[5];
			int x,y,k;
			scanf("%s",op);
			if(op[0]=='C'){
				scanf("%d%d%d",&x,&y,&k);
				change(x,y,k+1);
			}
			else{
				scanf("%d%d",&x,&y);
				printf("%d\n",queryco(x,y));
			}
		}
	}
    return 0;
}
