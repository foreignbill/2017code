#include<bits/stdc++.h>

#define lc (tire[id][0])
#define rc (tire[id][1])

using namespace std;

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}

const int maxn = 6001000;
const int maxdep = 19;

bool rev[maxn];
int cnt[maxn];
int tire[maxn][2];
int rt,tot;
int build(int dep){
    int now=tot++;
    if(dep>=0){
        tire[now][0]=build(dep-1);
        tire[now][1]=build(dep-1);
    }
    return now;
}
int push_UP(int id){
    cnt[id]=min(cnt[lc],cnt[rc]);
}
int update(int id,int dep,int x){
    if(dep==-1){
        cnt[id]++;
        return 0;
    }
    int t=(x>>dep&1);
    update(tire[id][t],dep-1,x);
    push_UP(id);
}
void solve(){
    int ans=0;
    int now=rt;
    for(int i=maxdep;i>=0;i--){
        if(rev[i]){
            if(cnt[tire[now][1]]==0){
                now=tire[now][1];
            } else {
                now=tire[now][0];
                ans+=(1<<i);
            }
        } else {
            if(cnt[tire[now][0]]==0){
                now=tire[now][0];
            } else {
                now=tire[now][1];
                ans+=(1<<i);
            }
        }
    }
    printf("%d\n",ans);
}
int n,m;
int main(){
	int x; 
    rt=build(maxdep);
    read(n,m); 
    for(int i=1;i<=n;i++){
        read(x);
        update(rt,maxdep,x);
    }
    for(int ii=1;ii<=m;ii++){
        read(x);
        for(int i=maxdep;i>=0;i--){
            if(x>>i&1){
                rev[i]^=1;
            }
        }
        solve();
    }
    return 0;
}
