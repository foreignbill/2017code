#include <bits/stdc++.h>
using namespace std;
vector<int> g[200010];
int n, arr[200010], dp[200010][2], fa[200010];
queue<int> Q;
void bfs() {
	Q.push(1);
	dp[1][0] = arr[1]; dp[1][1] = 0;
	while (!Q.empty()) {
		int w = Q.front(); Q.pop();
		for (auto t: g[w]) {
			if (t == fa[w]) continue;
			fa[t] = w;
			dp[t][0] = __gcd(dp[w][0], arr[t]);
			dp[t][1] = max(dp[w][0], dp[w][1] ? __gcd(dp[w][1], arr[t]) : arr[t]);
			Q.push(t);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	int u, v;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v); g[v].push_back(u);
	}
	bfs();
	for (int i = 1; i <= n; i++)
		cout << max(dp[i][0], dp[i][1]) << (i == n ? '\n' : ' ');
	return 0;
}
