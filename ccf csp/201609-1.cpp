#include <cstdio>

using namespace std;

int main(){
	int n,x,t,ans;
	scanf("%d",&n);
	scanf("%d",&x);
	scanf("%d",&t);
	ans = (t-x)>0?t-x:x-t; 
	x=t;
	for(int i=3;i<=n;i++){
		scanf("%d",&t);
		int tt = (t-x)>0?t-x:x-t;
		if(tt>ans){
			ans=tt;
		}
		x=t;
	}
	printf("%d\n",ans);
	return 0;
}
