#include <bits/stdc++.h>

#define LL long long

using namespace std;

LL n,s;

bool check(LL i,LL s){
	LL tmp = 0 , t=i;
	while(i){
		tmp+=i%10;
		i/=10;
	}
	return (t-tmp)>=s;
}

int main(){
	cin>>n>>s;
	LL ans = 0;
	for(LL i=s;i<=s+162 && i<=n;i++)
		if(check(i,s))
			ans++;
	if(s+162<n)
		ans+=n-(s+162);
	cout<<ans<<endl;
	return 0;
}
