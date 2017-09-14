#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int f[111111];
int a[111111];

int main(){
	int T,n,d;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		int mx = a[1];
		for(int i=1;i<=d+1;i++){
			f[i]=a[i];
		}
			
		for(int i=1;i+d+1<=n;i++){
			if(f[i]>mx) mx=f[i];
			f[i+d+1]=mx+a[i+d+1];
		}
		int ans = f[1];
		for(int i=1;i<=n;i++)
			if(f[i]>ans) ans = f[i];
		printf("%d\n",ans);
	}
	return 0;
} 
