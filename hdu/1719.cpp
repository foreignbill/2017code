#include <cstdio>

int main(){
	int n;
	while(~scanf("%d",&n)){
		if(!n){
			puts("NO!");
			continue;
		}
		n++;
		while(n%2==0) n/=2;
		while(n%3==0) n/=3;
		puts(n==1?"YES!":"NO!");
	}
	return 0;
}
