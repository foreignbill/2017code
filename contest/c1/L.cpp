#include<cstdio>
#include<algorithm>
#define LL long long
#define MAXN 1000001
#define BASE 131
#define MOD 1000000009
using namespace std;
char s[MAXN];
int fail[2][MAXN], ak[MAXN], ha[MAXN], n;
void init(int fail[])
{
	for (int i = 1, j = 0, p = 1; s[i]; i++){
		if (fail[i - j] + i < p)fail[i] = fail[i - j];
		else{
			if (p < i)p = i;
			while (s[p] == s[p - i])p++;
			fail[i] = p - i; j = i;
		}
	}
}
int main()
{
	ak[0] = 1;
	for (int i = 1; i<MAXN; i++)
		ak[i] = (LL)ak[i - 1] * BASE%MOD;
	while (scanf("%d%s", &n, s) == 2){
		if (n == 1){printf("1 1\n");continue;}
		init(fail[0]);
		reverse(s, s + n);
		init(fail[1]);
		int ans[2], pos[2];
		for (int i = 0; i <= 1; i++){
			reverse(s, s + n);
			ha[0] = s[0] - '0';
			for (int j = 1; j < n; j++)
				ha[j] = ((LL)ak[j] * (s[j] - '0') + ha[j - 1]) % MOD;
			for (int j = 1;; j++){
				pos[i] = fail[i][j] + j;
				if (pos[i] + 1 >= n){ ans[i] = j; break; }
				if (pos[i] + j >= n && fail[!i][j] >= n - 1 - pos[i]){ ans[i] = j; break; }
				if (pos[i] + j < n && fail[!i][j] >= n - 1 - pos[i] - j){
					int t1 = (ha[pos[i] + j - 1] + MOD - ha[pos[i]]) % MOD;
					int t2 = (ha[pos[i] - 1] + MOD - ha[pos[i] - j]) % MOD;
					if ((LL)t2*ak[j] % MOD == t1 && s[pos[i] + j] == s[pos[i] - j]){ ans[i] = j; break; }
				}
			}
		}
		if (ans[0] != ans[1])printf("%d %d\n", min(ans[0], ans[1]), 1);
		else printf("%d %d\n", ans[0], pos[0] == n ? n : (pos[0] + pos[1] + 1 == n ? 1 : 2));
	}
}

