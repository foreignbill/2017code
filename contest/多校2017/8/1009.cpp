#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e5+5;
int a[N],sum[N<<2],l[2][N<<2],r[2][N<<2],maxn[2][N<<2],XOR[N<<2],cover[N<<2],n,m;
void pushUp(int k,int lef,int rig) {
    sum[k]=sum[k<<1]+sum[k<<1|1];
    int mid=(rig+lef)>>1;
    for(int i=0;i<2;i++) {
        maxn[i][k]=max(max(maxn[i][k<<1],maxn[i][k<<1|1]),r[i][k<<1]+l[i][k<<1|1]);
        l[i][k]=l[i][k<<1];
        if(l[i][k]==mid-lef+1) l[i][k]+=l[i][k<<1|1];
        r[i][k]=r[i][k<<1|1];
        if(r[i][k<<1|1]==rig-mid) r[i][k]+=r[i][k<<1];
    }
    if(cover[k<<1]==cover[k<<1|1]) cover[k]=cover[k<<1];
    else cover[k]=-1;
}
void exchange(int k) {
    swap(l[0][k],l[1][k]);swap(r[0][k],r[1][k]);swap(maxn[0][k],maxn[1][k]);
}
void pushDown(int k,int lef,int rig) {
    int mid=(lef+rig)>>1;
    if(cover[k]!=-1) {
        cover[k<<1]=cover[k<<1|1]=cover[k];
        sum[k<<1]=cover[k<<1]?mid-lef+1:0,sum[k<<1|1]=cover[k<<1|1]?rig-mid:0;
        XOR[k<<1]=0;XOR[k<<1|1]=0;
        l[0][k<<1]=r[0][k<<1]=maxn[0][k<<1]=mid-lef+1-sum[k<<1];
        l[1][k<<1]=r[1][k<<1]=maxn[1][k<<1]=sum[k<<1];
        l[0][k<<1|1]=r[0][k<<1|1]=maxn[0][k<<1|1]=rig-mid-sum[k<<1|1];
        l[1][k<<1|1]=r[1][k<<1|1]=maxn[1][k<<1|1]=sum[k<<1|1];
        cover[k]=-1;
    }
    if(XOR[k]) {
        if(cover[k<<1]!=-1) cover[k<<1]^=1;
        else XOR[k<<1]^=1;
        sum[k<<1]=mid-lef+1-sum[k<<1];
        if(cover[k<<1|1]!=-1) cover[k<<1|1]^=1;
        else XOR[k<<1|1]^=1;
        sum[k<<1|1]=rig-mid-sum[k<<1|1];
        exchange(k<<1);exchange(k<<1|1);
        XOR[k]=0;
    }
}
void build(int k,int lef,int rig) {
    XOR[k]=0;cover[k]=-1;
    if(lef==rig) {
        if(a[lef]==1) sum[k]=1,l[0][k]=r[0][k]=maxn[0][k]=0,l[1][k]=r[1][k]=maxn[1][k]=1;
        else sum[k]=0,l[1][k]=r[1][k]=maxn[1][k]=0,l[0][k]=r[0][k]=maxn[0][k]=1;
        return;
    }
    int mid=(lef+rig)>>1;
    build(k<<1,lef,mid);build(k<<1|1,mid+1,rig);
    pushUp(k,lef,rig);
}
void update(int k,int lef,int rig,int ql,int qr,int c) {
    if(ql<=lef&&rig<=qr) {
        if(c<2) cover[k]=c,sum[k]=cover[k]?rig-lef+1:0,l[0][k]=r[0][k]=maxn[0][k]=rig-lef+1-sum[k],l[1][k]=r[1][k]=maxn[1][k]=sum[k],XOR[k]=0;
        else {
            if(cover[k]!=-1) cover[k]^=1;
            else XOR[k]^=1;
            exchange(k);sum[k]=rig-lef+1-sum[k];
        }
        return;
    }
    pushDown(k,lef,rig);
    int mid=(lef+rig)>>1;
    if(ql<=mid) update(k<<1,lef,mid,ql,qr,c);
    if(qr>mid) update(k<<1|1,mid+1,rig,ql,qr,c);
    pushUp(k,lef,rig);
}
int querySum(int k,int lef,int rig,int ql,int qr) {
    if(ql<=lef&&rig<=qr) return sum[k];
    pushDown(k,lef,rig);
    int mid=(lef+rig)>>1,ans=0;
    if(ql<=mid) ans+=querySum(k<<1,lef,mid,ql,qr);
    if(qr>mid) ans+=querySum(k<<1|1,mid+1,rig,ql,qr);
    return ans;
}
void queryLen(int k,int lef,int rig,int ql,int qr,int &ln,int &mn,int &rn) {
    if(ql<=lef&&rig<=qr) {
        if(ln==rn) {
            if(sum[k]==rig-lef+1) ln+=sum[k],rn+=sum[k],mn=ln;
            else ln+=l[1][k],rn=r[1][k],mn=max(mn,max(ln,maxn[1][k]));
        }
        else {
            if(sum[k]==rig-lef+1) rn+=sum[k],mn=max(mn,rn);
            else mn=max(mn,max(maxn[1][k],rn+l[1][k])),rn=r[1][k];
        }
        return;
    }
    pushDown(k,lef,rig);
    int mid=(lef+rig)>>1;
    if(ql<=mid) queryLen(k<<1,lef,mid,ql,qr,ln,mn,rn);
    if(qr>mid) queryLen(k<<1|1,mid+1,rig,ql,qr,ln,mn,rn);
}
int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",a+i);
        build(1,0,n-1);
        int ql,qr,c;
        while(m--) {
            scanf("%d%d%d",&c,&ql,&qr);
            if(c<=2) update(1,0,n-1,ql,qr,c);
            else if(c==3) printf("%d\n",querySum(1,0,n-1,ql,qr));
            else {
                int ln=0,mn=0,rn=0;
                queryLen(1,0,n-1,ql,qr,ln,mn,rn);
                printf("%d\n",max(ln,max(mn,rn)));
            }
        }
    }
    return 0;
}
