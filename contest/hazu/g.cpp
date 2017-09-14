#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

long long a[50005];

int main(){
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			scanf("%lld",a+i);
		int mx = 0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<i;j++)
				if(a[i]>a[j]){
					if(mx<i-j)
						mx = i-j;
					break;
				}
		}
		printf("%d\n",mx);
	}
	return 0;
} 
