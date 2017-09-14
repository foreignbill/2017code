#include <bits/stdc++.h>

#define LL long long

using namespace std;

int a[1000005];
int lmax[1000005],rmax[1000005];
int lmin[1000005],rmin[1000005];
int num[1000005*4];
int top;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	int i=1;
	while(i<=n){
		top++;
		rmax[i]=top;
		int j;
		for(j=i+1;j<=n;j++){
			if(a[j]>a[i]){
				num[top]=j;
				break;
			}
			rmax[j]=top;
		}
		i=j;
	}
	i=1;
	while(i<=n){
		top++;
		rmin[i]=top;
		int j;
		for(j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				num[top]=j;
				break;
			}
			rmin[j]=top;
		}
		i=j;
	}
	i=n;
	while(i>=1){
		top++;
		lmax[i]=top;
		int j;
		for(j=i-1;j>=1;j--){
			if(a[j]>a[i]){
				num[top]=j;
				break;
			}
			lmax[j]=top;
		}
		i=j;
	}
	i=n;
	while(i>=1){
		top++;
		lmin[i]=top;
		int j;
		for(j=i-1;j>=1;j--){
			if(a[j]<a[i]){
				num[top]=j;
				break;
			}
			lmin[i]=top;
		}
		i=j;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",num[lmin[i]]);
	puts("");
	LL ans = 0LL;
	for(int i=1;i<=n;i++){
		printf("%d %d\n",num[lmax[i]],num[rmax[i]]);
		LL l,r;
		l = i - num[lmax[i]] - 1;
		if(num[rmax[i]]==0) num[rmax[i]]=n+1;
		r = num[rmax[i]] - i - 1;
		ans +=(LL)a[i]*(1+l+r+l*r);
		cout<<ans<<endl;
	}
	for(int i=1;i<=n;i++){
		LL l,r;
		l = i - num[lmin[i]] - 1;
		if(num[rmin[i]]==0) num[rmin[i]]=n+1;
		r = num[rmin[i]] - i - 1;
		cout<<l<<" "<<r<<endl;
		ans -= (LL)a[i]*(1+l+r+l*r);
		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
} 
