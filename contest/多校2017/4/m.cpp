#include <bits/stdc++.h>

using namespace std;
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define PQ priority_queue
#define GT(type) greater < type >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define cls(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MOD = 998244353;
const int MAXN = 3e5 + 10;
const int MAXS = MAXN * 4;
typedef long long ll;
struct edge {
    int u,v,w;
	int next;
}mp[MAXS];
int c, n;
int cp[MAXS];
int head[MAXN * 2];
int d[MAXN * 2], pp[MAXN * 2];
int vis[MAXS];
void add(int u, int v, int w) {
    mp[c]=(edge){u, v, w, head[u]};
    head[u]=c++;
    mp[c]=(edge){v, u, w, head[v]};
    head[v]=c++;
}
queue<int> q;
ll tmp;
void del(int i) {
    vis[pp[i]] = vis[pp[i]^1] = 1;
    if(vis[cp[pp[i]]])
		return;
    vis[cp[pp[i]]] =1;
	vis[cp[pp[i]]^1] = 1;
    int t = cp[pp[i]];
    d[mp[t].u + n]--;
    if(d[mp[t].u + n] == 1)
		q.push(mp[t].u + n);
    tmp = tmp * mp[pp[i]].w % MOD;
}
int main() {
    int T; 
	scanf("%d", &T);
    while(T--) {
        c = 0;
        cls(vis,0); cls(head,-1); cls(d,0);
        scanf("%d", &n);
        lpi(i,1,n){
            int v1, w1, v2, w2;
            scanf("%d%d%d%d", &v1, &w1, &v2, &w2);
            d[v1 + n]++;
			d[v2 + n]++;
            add(i, v1 + n, w1);
            int t1 = c - 1;
            add(i, v2 + n, w2);
            int t2 = c - 1;
            cp[t1] = cp[t1^1] = t2;
            cp[t2] = cp[t2^1] = t1;
            pp[v1 + n] = t1;
            pp[v2 + n] = t2;
        }
        tmp = 1;
		lpi(i,n+1,n+n)	
			if(d[i] == 1) q.push(i);
        while(!q.empty()) {
            int t = q.front(); q.pop();
            del(t);
        }
        lpi(i,1,n) 
			if(!vis[head[i]]) {
	            int p = i, step = 1;
	            ll s[2] = {1, 1};
	            vis[head[i]] = vis[head[i]^1] = 1;
	            s[0] = s[0] * mp[head[i]].w % MOD;
	            p = mp[head[p]].v;
	            while(p != i) {
	                for(int j = head[p]; j != -1; j = mp[j].next) if(!vis[j]) {
	                    int v = mp[j].v;
	                    vis[j] = vis[j^1] = 1;
	                    s[step % 2] = s[step % 2] * mp[j].w % MOD;
	                    p = v;
	                    step++;
	                    break;
	                }
	            }
	            tmp = tmp * ((s[0] + s[1]) % MOD) % MOD;
        }
        printf("%lld\n", tmp);
    }
}
//http://paste.ubuntu.com/25231978/
