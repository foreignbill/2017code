#include <cstdio>

int main(){
	int tot=0;
	long long n,k;
	while(~scanf("%lld%lld",&n,&k)){
		long long ans;
		if(k<=n){
			ans = k;
		} else {
			k-=n;
			long long t = (k-1) / (n-1);
			if(t%2==0){
				ans = (k-1) % (n-1) + 1;
			} else {
				ans = (k-1) % (n-1) + 1;
				if(ans==(n-1))
					ans = n;
			}
		}
		printf("Case #%d: %d\n",++tot,ans);
	}
	return 0;
} 
