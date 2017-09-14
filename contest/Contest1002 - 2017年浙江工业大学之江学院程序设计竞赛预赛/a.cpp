#include <bits/stdc++.h>

using namespace std;

int k,n;

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&k,&n);
		if(k%(n+1)==0) puts("Z");
		else puts("L");
	}
	return 0;
} 
