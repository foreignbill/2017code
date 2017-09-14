#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[1111];
int st[1111];

int main(){
	int n,Mx=-1111;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>Mx) Mx=a[i];
		st[a[i]]++;
	}
	int ans=-1,pre=0;
	for(int i=1;i<=Mx;i++){
		if(st[i]==0)continue;
		if(pre==(n-st[i]-pre)){
			ans=i;
			break;
		}
		pre+=st[i];
	}
	printf("%d\n",ans);
	return 0;
} 
