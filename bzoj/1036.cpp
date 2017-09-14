#include <bits/stdc++.h>
#define N 30005 
#define M 60005
using namespace std;
int n,q,cnt,sz;//sz Ïß¶ÎÊ÷_number
int v[N],dep[N],size[N],head[N],fa[N];
int pos[N],bl[N];
//pos[i]  Ïß¶ÎÊ÷_number
//bl[i] top[i] 
struct node{
	int to,nxt;
}e[M];
void insert(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;
}
struct Tnd{
	int l,r,mx,sum;
}T[N<<2];

void dfs1(int id){
	size[id]=1;
	for(int i=head[id];i;i=e[i].nxt){
		if(e[i].to == fa[id]) continue;
		dep[e[i].to] = dep[id] + 1;
		fa[e[i].to] = id;
		dfs1(e[i].to);
		size[id] += size[e[i].to];
	}
}

void dfs2(int id,int chain){
	int k=0;sz++;
	pos[id] = sz;
	bl[id] = chain;
	for(int i=head[id];i;i=e[i].nxt)
		if(dep[e[i].to] > dep[id]  &&  size[e[i].to] > size[k])
			k=e[i].to;
	if(k==0)
		return;
	dfs2(k,chain);
	for(int i=head[id];i;i=e[i].nxt)
		if(dep[e[i].to] > dep[id] && e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}

void build(int tp,int l,int r){
	T[tp].l=l;T[tp].r=r;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(tp<<1,l,mid);
	build(tp<<1|1,mid+1,r);
}

void change(int tp,int p,int delta){
	int l=T[tp].l,r=T[tp].r,mid=(l+r)>>1;
	if(l==r){
		T[tp].sum = T[tp].mx = delta;
		return;
	}
	if(p<=mid)
		change(tp<<1,p,delta);
	else
		change(tp<<1|1,p,delta);
	T[tp].sum = T[tp<<1].sum + T[tp<<1|1].sum;
	T[tp].mx = max(T[tp<<1].mx,T[tp<<1|1].mx);
}

int querymx(int tp,int x,int y){
	int l = T[tp].l,r = T[tp].r,mid=(l+r)>>1;
	if(l==x && r==y)
		return T[tp].mx;
	else if(y<=mid) return querymx(tp<<1,x,y);
	else if(x>mid)  return querymx(tp<<1|1,x,y);
	else return max(querymx(tp<<1,x,mid),querymx(tp<<1|1,mid+1,y));
}

int querysum(int tp,int x,int y){
	int l = T[tp].l,r = T[tp].r,mid=(l+r)>>1;
	if(l==x && r==y)
		return T[tp].sum;
	else if(y<=mid) return querysum(tp<<1,x,y);
	else if(x>mid)  return querysum(tp<<1|1,x,y);
	else return querysum(tp<<1,x,mid)+querysum(tp<<1|1,mid+1,y);
}

int solvemx(int x,int y){
	int mx=-INT_MAX;
	while(bl[x]!=bl[y]){
		if(dep[bl[x]]<dep[bl[y]])
			swap(x,y);
		mx=max(mx,querymx(1,pos[bl[x]],pos[x]));
		x=fa[bl[x]];
	}
	if(pos[x]>pos[y])
		swap(x,y);
	mx=max(mx,querymx(1,pos[x],pos[y]));
    return mx;
}

int solvesum(int x,int y){
	int sum=0;
	while(bl[x]!=bl[y]){
		if(dep[bl[x]]<dep[bl[y]])
			swap(x,y);
		sum+=querysum(1,pos[bl[x]],pos[x]);
		x=fa[bl[x]];
	}
	if(pos[x]>pos[y])
		swap(x,y);
	sum+=querysum(1,pos[x],pos[y]);
    return sum;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		insert(x,y);insert(y,x);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	dfs1(1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=n;i++)
		change(1,pos[i],v[i]);
	scanf("%d",&q);
	char cho[20];
	int x,y;
	for(int i=1;i<=q;i++){
		scanf("%s%d%d",cho,&x,&y);
		if(cho[0]=='C'){
			v[x]=y;
			change(1,pos[x],y);
		} else {
			if(cho[1]=='M'){
				printf("%d\n",solvemx(x,y));
			} else {
				printf("%d\n",solvesum(x,y));
			}
		}
	}
	return 0;
}
