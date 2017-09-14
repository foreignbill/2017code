#include<bits/stdc++.h>
using namespace std;
#define maxn 100050
int a[maxn];
int ans[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,k; 
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		int len=1;
		memset(ans,0,sizeof ans);
		ans[0]=a[0];
		for(int i=1;i<n;i++){
			if(a[i]>=ans[len-1]) ans[len++]=a[i];
			else{
				int pos=upper_bound(ans,ans+len,a[i])-ans;
				ans[pos]=a[i];
			}
		}
		if(n-k<=len){
			puts("A is a magic array.");
		} else puts("A is not a magic array.");
	}
	return 0;
}
