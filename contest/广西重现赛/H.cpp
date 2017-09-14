#include <bits/stdc++.h>

using namespace std;

int a[1000005],x,n;

int main(){
	while(~scanf("%d",&n)){
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			a[x]++;
		}
		int cnt = 0;
		for(int i=1;i<=1000000;i++){
			if(i>=3)
				if(a[i] && a[i-1] && a[i-2]){
					a[i]--;a[i-1]--;a[i-2]--;
					cnt++; 
				}
			cnt += a[i]/2;
			a[i] %= 2;
		}
		printf("%d\n",cnt);
	}
	return 0;
} 
