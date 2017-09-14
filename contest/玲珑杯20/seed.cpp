#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000005;
char A[MAXN], B[MAXN], c;
unsigned seed;
int n, m, Q, typ, p, k;
long long ans;
inline unsigned Rand(){
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return seed;
}
inline void Gen(){
	for (int i = 1; i <= n; i ++)
		A[i] = Rand() % 26 + 'a';
	for (int i = 1; i <= m; i ++)
		B[i] = Rand() % 26 + 'a';
}
inline void GetQuery(){
	p = Rand() + typ * ans & 1;
	if (!p)
		k = (Rand() + typ * ans) % (n + 1), n ++;
	else k = (Rand() + typ * ans) % (m + 1), m ++;
		c = (Rand() + typ * ans) % 26 + 'a';
} 
int main(){
	cin>>n>>m>>Q>>typ>>seed;
	Gen();
	printf("%s\n",A+1);
	printf("%s\n",B+1);
	GetQuery();
	return 0;
}
