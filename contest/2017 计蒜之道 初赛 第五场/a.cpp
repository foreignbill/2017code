#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[1000];

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=m;i++)
			scanf("%d",a+i);
		if(n==0){
			puts("0");
			return 0;
		}
	    if(n==1){
			puts("0");
			return 0;
		}
		sort(a+1,a+1+m);
		int tot=0,ans=-1;
		for(int i=m;i>=1;i--){
			if(i<m) n++;
			tot+=a[i];
			if(tot>=n){
				printf("%d\n",m-i+1);
				return 0;
			}
		}
		puts("Impossible");
	}
	return 0;
}
