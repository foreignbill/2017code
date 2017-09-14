#include <bits/stdc++.h>

using namespace std;

map<int, long long> mp, Mp;
int n, m;
char S[100];

long long calc(int x, int y) {
	if (x > n) return 0;
	auto it = Mp.find(x);
	if (it != Mp.end()) {
		if (y == 0) return mp[x];
		else return it->second;
	}
	long long s = 0;
	int X = x;
	while (x <= n) {
		s += x;
		x = (x << 1) + 1;
	}
	Mp[X] = X;
	mp[X] = s;
	if (y == 0) return s;
	else return X;
}

void up(int x) {
	long long s = calc(x, 0);
	while (x != 1) {
		int X = x / 2;
		int t = calc(X, 1);
		mp[X] = max(calc(x ^ 1, 0), s) + t;
		s += t;
		x >>= 1;
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		mp.clear(); 
		for (int i = 1; i <= m; ++i) {
			scanf("%s", S);
			up(n);
			if (S[0] == 'q') {
				int x;
				scanf("%d", &x);
				long long s = calc(x, 0);
				long long ans = max(calc(x << 1, 0), calc(x << 1 | 1, 0)) + calc(x, 1);
				while (x != 1) {
					int X = x / 2;
					int Y = (x ^ 1);
					long long xx = calc(X, 1);
					long long yy = calc(Y, 0);
					ans = max(ans, s + xx + yy);
					s += xx;
					x = X;
				}
				printf("%lld\n", ans);
			}
			else {
				int x;
				long long y;
				scanf("%d%lld", &x, &y);
				long long s = calc(x, 0) - calc(x, 1) + y;
				Mp[x] = y;
				mp[x] = s;
				up(x);
			}
		}
	}
	return 0;
}
