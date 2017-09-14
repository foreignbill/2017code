#include <cstdio>

using namespace std;

bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return 0;
	return 1;
}

int main(){
	freopen("prime.txt","w",stdout);
	for(int i=2;i<=100000000;i++)
		if(isprime(i)) printf("%d,",i); 
	return 0;
} 
