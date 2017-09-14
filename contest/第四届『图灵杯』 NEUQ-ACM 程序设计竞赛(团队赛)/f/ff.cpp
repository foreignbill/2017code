#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int maxn=110;
#define mod(x) ((x)%MOD)
struct mat {
	int m[maxn][maxn];
}
unit;
int num[maxn];
ll n,k;
mat operator *(mat a,mat b) {
	mat ret;
	ll x;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		x=0;
		for(int k=0; k<n; k++)  x += mod((ll)a.m[i][k]*b.m[k][j]);
		ret.m[i][j]=mod(x);
	}
	return ret;
}
void init_unit() {
	memset(unit.m,0,sizeof unit.m);
	return;
}
mat pow_mat(mat a,ll n) {
	mat ret = unit;
	while(n) {
		if(n&1) ret=ret*a;
		a = a*a;
		n>>=1;
	}
	return ret;
}
int main() {
	freopen("input.txt","r",stdin); 
	while(cin>>n>>k) {
		init_unit();
		mat a;
		for(int i=0; i<n; i++)
			cin>>num[i];
		for(int i=0; i<n; i++)
			cin>>unit.m[0][i];
		for(int i=1; i<n; i++)
			unit.m[i][i-1]=1;
		unit=pow_mat(unit,k-n-1);
		ll ans=0,x;
		for(int i=0;i<n;i++){
			x = mod((ll)unit.m[0][i]*num[n-i-1]);
			ans += mod(x);
		}
		printf("%lld\n",ans);
	}
}
