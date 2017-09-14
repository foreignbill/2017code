#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int p=0,x=0,a;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			x^=a;
			p+=(a>1);
		}
		if( (p==0&&n&1) || (p>1&&x==0) ) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
/*
Nim 博弈 
若所有堆都为1且SG值为0，则共有偶数堆石子，故先手胜。 
i)只有一堆石子数大于1时，我们总可以对该石子操作，使操作后堆数为奇数且所有堆的石子数均为1； 

ii)有超过一堆的石子数1时，先手将SG值变为0即可，且总还存在某堆石子数大于1 
*/
