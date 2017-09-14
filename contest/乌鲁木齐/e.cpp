#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll p[]={0, 1, 8, 49, 288, 1681, 9800, 57121,
332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048,
76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328, -1};
int main(){
	int T,tot=1;
	ll n;
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		ll res=-1;
		for(int i=1;p[i]!=-1;i++){
			if(p[i]<n) continue;
			if(p[i]>=n){
				res=p[i];
				break;
			}
		}
		printf("Case #%d: %lld\n",tot++,res);
	}
	return 0;
}
