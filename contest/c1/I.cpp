#include<cstdio>
inline int mul(int a, int b, int mod){
	return (long long)a*b & ((1 << mod) - 1);
}
int power(int a, int b, int mod){
	int ret = 1;
	for (int t = a; b; b >>= 1){
		if (b & 1)ret = mul(ret, t, mod);
		t = mul(t, t, mod);
	}
	return ret;
}
int main()
{
	int n, a;
	while (scanf("%d%d", &n, &a) == 2){
		if (a & 1)printf("1\n");
		else{
			int ans = 0;
			for (int i = 2; i <= n; i += 2)
				ans += power(i, a, n) == power(a, i, n);
			ans += (1 << n) >> ((n + a - 1) / a);
			ans -= n >> ((n + a - 1) / a);
			printf("%d\n", ans);
		}
	}
}