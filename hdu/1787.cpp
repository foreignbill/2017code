#include <cstdio>

int count(int n){
	int res = n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i;
			res -= res/i;
		}
		while(n%i==0) n/=i;
	}
	if(n>1) res -= res/n;
	return res;
} 

int main(){
	int n;
	while(scanf("%d",&n),n){
		printf("%d\n",n-1-count(n));
	}
	return 0;
} 
