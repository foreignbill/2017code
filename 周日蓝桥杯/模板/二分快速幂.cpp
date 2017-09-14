#include <cstdio>

int pow(int a,int n){
	if(n==0) return 1;
	int tmp = pow(a,n/2);
	if(n%2) return tmp*tmp*a;
	return tmp*tmp;
} 

int main(){
	printf("%d\n",pow(2,16));
	return 0;
}
