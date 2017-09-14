#include <bits/stdc++.h>

using namespace std;

int pow(int a,int n){
	if(n==0) return 1;
	int tmp = pow(a,n/2);
	tmp*=tmp;
	if(n&1) return tmp*a;
	return tmp;
}

int f(int n,int i){
	if(i==1) return n;
	int tmp = f(n,i-1);
	return pow(n,tmp);
} 

int main(){
	int n = 5;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",f(i,j));
		puts("");
	}
	return 0;
} 
