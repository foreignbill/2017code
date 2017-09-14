#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 10005;
map<ll,int> mp;
ll a[maxn];
ll p[maxn];

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	mp.clear();
	mp[0]=0;
	ll sum = 0;
	for(int i=1;i<=n;i++){
		sum += a[i];
		p[i]=sum;
		if(mp.find(sum)==mp.end()){
			mp[sum]=i;
		} else {
			if(mp[sum]>i)
				mp[sum]=i;
		}
	}
	int ansi=-1,ansj=-1;
	for(int j=1;j<=n;j++){
		ll nows = p[j];
		nows -= (ll)k;
		if(mp.find(nows)==mp.end()) continue;
		int ii = mp[nows];
		if(ansi==-1 && j>=ii+1){
			ansi=ii+1;
			ansj=j;
			continue;
		}
		if(ii+1<ansi && j>=ii+1){
			ansi=ii+1;
			ansj=j;
			continue;
		}
		if(ii+1==ansi && j<ansj && j>=ii+1){
			ansi=ii+1;
			ansj=j;
		}
	}
	if(ansi!=-1) printf("%d %d\n",ansi,ansj);
	else puts("No Solution");
	return 0;
} 
