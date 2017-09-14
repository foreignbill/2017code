#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
inline ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	int n;ll x;
	read(n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		read(x);
		ans=gcd(ans,abs(x));
	}
	printf("%lld\n",ans);
	return 0;
} 
