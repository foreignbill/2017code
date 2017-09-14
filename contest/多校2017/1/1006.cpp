#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define mm(a) memset(a,0,sizeof a)

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 100010;
vector<int> e[maxn];
int a[maxn], b[maxn];
int d[maxn];
int n, m, k, i, j;

void add(int num, int x) {
	e[x].push_back(num);
    return;
}

int dfs(int * a, int x, int dd) {
    d[x] = dd;
    for (int k = 0; k <e[x].size(); k++) {
        int y = e[x][k];
        if (d[y] == 0)
            dfs(a, y, dd+1);
        else {
            ++a[0];
            a[a[0]] = abs(d[x] - d[y]) + 1;
        }
    }
    return 0;
}

void work(int * a, int n) {
    for (int i = 0; i < n; ++i) e[i].clear();
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        add(i, k);
    }
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i)
        if (d[i] == 0)
            dfs(a, i, 1);
    return;
}

int main() {
    int tot = 1;
    while (~scanf("%d%d", &n, &m)) {
        mm(a);mm(b);
        work(a,n);
        work(b,m);
        ll ans=1;
        for (i = 1; i <= a[0]; ++i) {
            ll tmp = 0;
            for (j = 1; j <= b[0]; ++j)
                if (a[i] % b[j] == 0)
                    tmp = (tmp + b[j]) % mod;
            ans = ans * tmp %  mod;
        }
        printf("Case #%d: %lld\n", tot++, ans);
    }
    return 0;
}
