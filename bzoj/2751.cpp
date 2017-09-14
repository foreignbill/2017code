#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int maxk = 1e5+5;
int n,m,k;
map<int,int> mp;
ll sum[maxk];
struct node{
	int id,i;
}info[maxk];

inline bool comp(node A,node B){
	if(A.id==B.id)
		return A.i<B.i;
	return A.id<B.id;
}

ll power(ll a,ll n){
	if(!n) return 1ll;
	ll ret=power(a,n/2);
	ret=ret*ret%mod;
	if(n&1) return ret*a%mod;
	return ret;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	ll t=(ll)n*(n+1)/2%mod;
	for(int i=1;i<=k;i++)
		scanf("%d%d",&info[i].id,&info[i].i);
	sort(info+1,info+1+k,comp);
	ll res=1;
	int tot=0;
	mp.clear();
	for(int i=1;i<=k;i++){
		if(i!=1 && info[i].id==info[i-1].id && info[i].i==info[i-1].i){
			continue; 
		} 
		int id=info[i].id;
		if(mp.find(id)==mp.end()){
			tot++;
			mp[id]=tot;
			sum[tot]+=info[i].i;
		} else {
			sum[mp[id]]+=info[i].i;
		}
	}
	for(int i=1;i<=tot;i++)
		res = res * (t - sum[i]) % mod;
	res = res * power(t,m-tot) % mod;
	res = (res + mod) % mod;
	printf("%lld\n",res);
	return 0;
} 
