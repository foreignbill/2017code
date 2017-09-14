#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define cl(a) memset((a),0,sizeof(a))
#ifdef HandsomeHow
#define dbg(x) cerr << #x << " = " << x << endl
#else
#define dbg(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=1000000007;
const double pi=acos(-1.0);
inline void gn(long long&x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
ll gcd(ll a,ll b){return a? gcd(b%a,a):b;}
ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}
const int maxn = 1000;
int sz[maxn];
vector<int>E[maxn];
void dfs(int u){
    sz[u]=1;
    for(auto it:E[u]){
        dfs(it);
        sz[u]+=sz[it];
    }
}
void solve(int n, int k){
    rep(i,0,n-1)E[i].clear();
    rep(i,1,n-1)E[(i-1)/k].pb(i);
    dfs(0);
    int ret=0;
    rep(i,0,n-1){
        ret^=sz[i];
    }
    printf("%d\n",ret);
}
int main(){
    int T;gn(T);while(T--){
        int n,k;
        gn(n);gn(k);
        solve(n,k);
    }
    return 0;
}
