#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define calm (l+r)>>1

const int INF=1e9+7;
const int MAXN=200000;

int ll[MAXN<<2],rr[MAXN<<2],llen[MAXN<<2],rlen[MAXN<<2],sum[MAXN<<2];
int n,m;

void pushup(int rt){
    sum[rt]=max(sum[rt<<1],sum[rt<<1|1]);
    ll[rt]=ll[rt<<1];   rr[rt]=rr[rt<<1|1];
    llen[rt]=llen[rt<<1];   rlen[rt]=rlen[rt<<1|1];
    if(ll[rt<<1]==rr[rt<<1]){
        if(rr[rt<<1]==ll[rt<<1|1]){
            llen[rt]=llen[rt<<1]+llen[rt<<1|1];
        }
    }
    if(ll[rt<<1|1]==rr[rt<<1|1]){
        if(ll[rt<<1|1]==rr[rt<<1]){
            rlen[rt]=rlen[rt<<1|1]+rlen[rt<<1];
        }
    }
    if(rr[rt<<1]==ll[rt<<1|1]){
        sum[rt]=max(sum[rt],rlen[rt<<1]+llen[rt<<1|1]);
    }
    sum[rt]=max(sum[rt],max(llen[rt],rlen[rt]));
}

void build(int l,int r,int rt){
    ll[rt]=rr[rt]=llen[rt]=rlen[rt]=sum[rt]=0;
    if(l==r){
        int x;scanf("%d",&x);
        ll[rt]=rr[rt]=x;
        llen[rt]=rlen[rt]=sum[rt]=1;
        return;
    }
    int m=calm;
    build(lson);build(rson);
    pushup(rt);
}

struct node{
    int ll,rr,llen,rlen,sum;
    node(){}
    node(int ll,int rr,int llen,int rlen,int sum):ll(ll),rr(rr),llen(llen),rlen(rlen),sum(sum){}
};
node merge(node left,node right){
    node ans;
    ans.sum=max(left.sum,right.sum);
    ans.ll=left.ll; ans.rr=right.rr;
    ans.llen=left.llen; ans.rlen=right.rlen;
    if(left.ll==left.rr){
        if(left.rr==right.ll){
            ans.llen=left.llen+right.llen;
        }
    }
    if(right.ll==right.rr){
        if(left.rr==right.ll){
            ans.rlen=left.rlen+right.rlen;
        }
    }
    if(left.rr==right.ll){
        ans.sum=max(ans.sum,left.rlen+right.llen);
    }
    ans.sum=max(ans.sum,max(ans.llen,ans.rlen));
    return ans;
}
node query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return node(ll[rt],rr[rt],llen[rt],rlen[rt],sum[rt]);
    }
    int m=calm;
    if(R<=m)return query(L,R,lson);
    if(L> m)return query(L,R,rson);
    return merge(query(L,R,lson),query(L,R,rson));
}
int main(){
    while(scanf("%d",&n),n){
        if(n==0)break;
        scanf("%d",&m);
        build(1,n,1);
        for(int i=1;i<=m;i++){
            int L,R;scanf("%d%d",&L,&R);
            printf("%d\n",query(L,R,1,n,1).sum);
        }
    }
    return 0;
}
