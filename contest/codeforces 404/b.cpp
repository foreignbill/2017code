#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,l,r;
	int Maxn=-INT_MAX,Maxm=-INT_MAX,Minn=INT_MAX,Minm=INT_MAX;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		Maxn=max(Maxn,l);
		Minn=min(Minn,r);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&l,&r);
		Maxm=max(Maxm,l);
		Minm=min(Minm,r);
	}
	int ans=-INT_MAX;
	ans=max(ans,Maxm-Minn);
	ans=max(ans,Maxn-Minm);
	printf("%d\n",ans>0?ans:0);
	return 0;
} 
