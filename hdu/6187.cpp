#include <bits/stdc++.h> 
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;
const int N = 100005;

struct Edge{
    int from,to,w;
    Edge(){}
    Edge(int x,int y,int z):from(x),to(y),w(z){}
    bool operator < (const Edge& a) const{return w > a.w;}
} edges[N * 2];

int f[N];
int F(int x){return f[x]==x ? x : (f[x]=F(f[x]));}

bool vis[N];
P kruskal(int n, int m){
    int treenum = n; //forests
    for (int i = 1;i <= n; i++) f[i] = i;
    sort(edges, edges + m);
    int cnt = 0, ans = 0;
    for (int i = 0; i < m; i++){
        Edge &e = edges[i];
        if (F(e.from) == F(e.to)) continue;
        f[F(e.from)] = F(e.to);
        treenum--;
        ans += e.w;
    }
    return P(treenum, ans);
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, x, y, u, v, c, m;
    for (; scanf("%d%d", &n, &m)==2;){
        for (int i = 1; i <= n; i++) scanf("%d%d", &x, &y);
        int all = 0;
        for (int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &c);
            edges[i] = Edge(u, v, c);
            all += c;
        }
        P p = kruskal(n, m);
        printf("%d %d\n", m-(n-p.fi), all - p.se);
    }
    return 0;
}
