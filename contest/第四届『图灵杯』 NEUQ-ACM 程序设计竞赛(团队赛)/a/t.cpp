#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		double tmp = 1.0/(3*n+1); 
		printf("%.9lf\n",tmp);	
	}
	return 0;
} 
