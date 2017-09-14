#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		if(gcd(a,b)==1){
			printf("%10d%10d    Good Choice\n\n",a,b);
		} else {
			printf("%10d%10d    Bad Choice\n\n",a,b);
		}
	}
	return 0;
}