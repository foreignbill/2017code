#include <bits/stdc++.h>
#define N 100005 
#define M 500005
using namespace std;
int n,q,cnt,sz;//sz Ïß¶ÎÊ÷_number
int v[N],dep[N],size[N],head[N],fa[N];
int ith[N]; 
int c[N],ans[M],a[N];
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

map<int ,int >ma;
int lowbit(int x) {
	return x&(-x);
}
void update(int x,int val) {
	while(x<=N) {
		c[x]+=val;
		x+=lowbit(x);
	}
}
int sum(int x) {
	int s=0;
	while(x) {
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}

int main(){
	int T;
	while(~scanf("%d",&n)){
	    for(int i=1;i<=n;i++)
	        scanf("%d",&v[i]);
	    for(int i=1;i<n;i++){
	        int x,y;
	        scanf("%d%d",&x,&y);
	        insert(x,y);insert(y,x);
	    }
	    dfs1(1);
	    dfs2(1,1);
		int pre=1;
		for(int i=1;i<=n;i++){
			a[pos[i]]=v[i];
			ith[pos[i]]=i;
		}
		memset(c,0,sizeof c);
		for(int j=1;j<=n;j++){
			int s = sum(j-1);
			if(ma.find(a[j])==ma.end())
				update(j,1);
			else{
				update(ma[a[j]],-1);
				update(j,1);;
			}
			update(j,s);
			ma[a[j]]=j;
		}
		printf("%lld\n",sum(n));
	}
    return 0;
}

