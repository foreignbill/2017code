#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int MAXN = 3e5 + 10;
const int MAXS = MAXN * 4;
typedef long long ll;
struct edge {
    int u, v, w, next;
}ed[MAXS];
int ecnt, n;
int cp[MAXS];
int head[MAXN * 2];
int deg[MAXN * 2], past[MAXN * 2], vis[MAXS];
void add(int u, int v, int w) {
    ed[ecnt] = (edge) {u, v, w, head[u]};
    head[u] = ecnt++;
    ed[ecnt] = (edge) {v, u, w, head[v]};
    head[v] = ecnt++;
}
void log(int x) {
    cout << ed[x].u << ' ' << ed[x].v << ' ' << ed[x].w << endl;
}
queue<int> q;
ll tmp;
void del(int i) {
    vis[past[i]] = vis[past[i]^1] = 1;
    if(vis[cp[past[i]]]) return;
    vis[cp[past[i]]] = vis[cp[past[i]]^1] = 1;
    int t = cp[past[i]];
    deg[ed[t].u + n]--;
    if(deg[ed[t].u + n] == 1) q.push(ed[t].u + n);
    tmp = tmp * ed[past[i]].w % MOD;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int T; scanf("%d", &T);
    while(T--) {
        ecnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(head, -1, sizeof(head));
        memset(deg, 0, sizeof(deg));
       // memset(vn, 0, sizeof(vn));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            int v1, w1, v2, w2;
            scanf("%d%d%d%d", &v1, &w1, &v2, &w2);
            deg[v1 + n]++; deg[v2 + n]++;
            add(i, v1 + n, w1);
            int t1 = ecnt - 1;
            add(i, v2 + n, w2);
            int t2 = ecnt - 1;
            cp[t1] = cp[t1^1] = t2;
            cp[t2] = cp[t2^1] = t1;
            past[v1 + n] = t1;
            past[v2 + n] = t2;
        }
        tmp = 1;
        for(int i = n + 1; i <= 2 * n; i++) if(deg[i] == 1) q.push(i);
        while(!q.empty()) {
            int t = q.front(); q.pop();
            del(t);
        }
        //cout << tmp << endl;
        for(int i = 1; i <= n; i++) if(!vis[head[i]]) {
            int p = i, step = 1;
            ll s[2] = {1, 1};
            vis[head[i]] = vis[head[i]^1] = 1;
            s[0] = s[0] * ed[head[i]].w % MOD;
            p = ed[head[p]].v;
            while(p != i) {
                for(int j = head[p]; j != -1; j = ed[j].next) if(!vis[j]) {
                    int v = ed[j].v;
                    vis[j] = vis[j^1] = 1;
                    s[step % 2] = s[step % 2] * ed[j].w % MOD;
                    p = v;
                    step++;
                    break;
                }
            //cout << p << endl;
            }
           // cout << s[0] << ' ' << s[1] << endl;
            tmp = tmp * ((s[0] + s[1]) % MOD) % MOD;
        }
        printf("%lld\n", tmp);
    }
}
