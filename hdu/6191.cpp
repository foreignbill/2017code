#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int bin[30];
int n,m;
int a[N],root[N];
struct trie{
    int cnt;
    int ch[N*30][2],sum[N*30];
    void init(){
        cnt = 0;
        memset(ch,0,sizeof ch);
        memset(sum,0,sizeof sum);
    }
    int insert(int x,int val){
        int tmp,y;tmp=y=++cnt;
        for(int i=29;i>=0;i--)
        {
            ch[y][0]=ch[x][0];ch[y][1]=ch[x][1];
            sum[y]=sum[x]+1;
            int t=val&bin[i];t>>=i;
            x=ch[x][t];
            ch[y][t]=++cnt;
            y=ch[y][t];
        }
        sum[y]=sum[x]+1;
        return tmp;
    }
    int query(int l,int r,int val){
        int tmp=0;
        for(int i=29;i>=0;i--)
        {
            int t=val&bin[i];t>>=i;
            if(sum[ch[r][t^1]]-sum[ch[l][t^1]])
                tmp+=bin[i],r=ch[r][t^1],l=ch[l][t^1];
            else r=ch[r][t],l=ch[l][t];
        }
        return tmp;
    }
}trie;

int in[N],out[N],cnt;

vector<int> e[N];

void dfs(int id,int fa){
    in[id] = ++cnt;
    root[cnt] = trie.insert(root[cnt-1],a[id]);
    for(auto ep:e[id]){
        if(ep == fa) continue;
        dfs(ep,id);
    }
    out[id]=cnt;
}

int main(){
    bin[0]=1;for(int i=1;i<=30;i++)bin[i]=bin[i-1]<<1;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=2;i<=n;i++){
            int v; 
            v=read();
            e[v].push_back(i);
        }
        cnt=0;
        trie.init(); 
        dfs(1,0);
        int u,x;
        while(m--){
            u=read();x=read();
            printf("%d\n",trie.query(root[in[u]-1],root[out[u]],x));
        }
    }
    return 0;
}
