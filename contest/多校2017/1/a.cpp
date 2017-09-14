#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int m;
	int tot=0;
	while(~scanf("%d",&m)){
		int ans = (int)(m*log(2)/log(10));
		printf("Case #%d: %d\n",++tot,ans);
	}
	return 0;
} 
