#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n;
LL a[111111];
LL b[111111];

LL S;

int main(){
	cin>>n>>S;
	for(int i=1;i<=n;i++)
		scanf("%I64d",a+i);
	int L=0,R=n;
	int ans=1;
	LL cost=0;
	while(L<=R){
		int mid=(L+R)/2;
		memcpy(b,a,sizeof(a));
		for(int i=1;i<=n;i++)
			b[i]+=(LL)mid*i;
		sort(b+1,b+1+n);
		LL sum=0;
		for(int i=1;i<=mid;i++)
			sum+=b[i];
		if(sum<=S){
			L=mid+1;
			ans=mid;
			cost=sum;
		} else {
			R=mid-1;
		}
	}
	cout<<ans<<" "<<cost<<endl;
	return 0;
} 
