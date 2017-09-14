#include <bits/stdc++.h>

using namespace std;

int main(){
	int T;
	long long x,l,r;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&x,&l,&r);
		long long L = (x+r-1)/r;
		long long R = x/l;
		if(L<=R) puts("QWQ");
		else puts("TAT");
	}
	return 0;
} 
