#include <cstdio>

int main(){
	int n,x,t,ans=1;
	scanf("%d",&n);
	scanf("%d",&x);
	for(int i=2;i<=n;i++){
		scanf("%d",&t);
		ans+=(x!=t);
		x=t;
	}
	printf("%d\n",ans);
	return 0;
}
