#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	freopen("input.txt","w",stdout);
	printf("1\n");
	for(int i=1;i<=1;i++){
		printf("100000 100000 100000\n");
		for(int i=1;i<=50000;i++){
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+1,i); 
		}
	}
	return 0;
} 
