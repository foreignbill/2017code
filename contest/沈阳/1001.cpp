#include <bits/stdc++.h>

#define rank rankk
using namespace std;

int sum[200001], rank[200001], x[200001], y[200001], Sa[200001];
int height[200001];
int str[200001];
int Log[200001];
int d[100001][19];
int n;
void Sort(int *a, int* b, int* c, int n, int m)
{
	for (int i = 0; i <= m; i ++) sum[i] = 0;
	for (int i = 1; i <= n; i ++) sum[c[i]] ++;
	for (int i = 1; i <= m; i ++) sum[i] += sum[i - 1];
	for (int i = n; i >= 1; i --) b[sum[c[a[i]]] --] = a[i];
}
void Make_Sa()
{
	for (int i = 1; i <= n; i ++)
		x[i] = str[i], rank[i] = i;
	Sort(rank, Sa, x, n, 256);
	rank[Sa[1]] = 1;
	for (int i = 2; i <= n; i ++)
		rank[Sa[i]] = rank[Sa[i - 1]] + (x[Sa[i - 1]] != x[Sa[i]]);
	for (int i = 1; i <= n; i <<= 1)
	{
		for (int j = 1; j <= n; j ++)
			x[j] = rank[j], y[j] = i + j <= n ? rank[i + j] : 0;
		Sort(Sa, rank, y, n, n), Sort(rank, Sa, x, n, n);
		rank[Sa[1]] = 1;
		for (int j = 2; j <= n; j ++)
			rank[Sa[j]] = rank[Sa[j - 1]] + (x[Sa[j - 1]] != x[Sa[j]] || y[Sa[j - 1]] != y[Sa[j]]);
		if (rank[Sa[n]] == n) return ;
	}
}
void get_height(){
	int p = 0;
	for (int i = 1; i <= n; i ++){
		if (p) p --;
		if (rank[i] != 1)
			while (str[i + p] == str[Sa[rank[i] - 1] + p]) ++ p;
		height[rank[i]] = p;
	}
}
int QueryLCP(int x, int y){
	if (x == y) return n - Sa[x] + 1;
	if (x > y) swap(x, y);
	x ++;
	if (x == y) return height[x];
	int k = Log[y - x + 1];
	return min(d[x][k], d[y - (1 << k) + 1][k]);
}

char a[200001];
int main(){
	int T, k;
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &k);
		scanf("%s", a + 1);
		n = (int )strlen(a + 1);
		for (int i = 1; i <= n; i ++) str[i] = a[i];
		
		Make_Sa();
		get_height();
		
		long long ans = 0;
		Log[1] = 0;
		for (int i = 2; i <= n; i ++)
			Log[i] = Log[i >> 1] + 1;
		for (int i = 1; i <= n; i ++)
			d[i][0] = height[i];
		for (int j = 1; j <= Log[n]; j ++)
		{
			int tmp = (1 << j);
			for (int i = 1; i + tmp - 1 <= n; i ++)
			{
				d[i][j] = d[i + (1 << (j - 1))][j - 1];
				if (d[i][j - 1] < d[i][j]) d[i][j] = d[i][j - 1];
			}
		}
		int lst = 0;
		for (int i = 1; i <= n - k + 1; i ++) {
			int tmp = QueryLCP(i, i + k - 1);
			ans += max(tmp - min(lst, height[i]), 0);
			lst = tmp;
		}
		k ++;
		for (int i = 1; i <= n - k + 1; i ++) {
			int tmp = QueryLCP(i, i + k - 1);
			ans -= max(tmp - min(lst, height[i]), 0);
			lst = tmp;
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i ++) Sa[i] = height[i] = rank[i] = 0;
	}
	return 0;
}
