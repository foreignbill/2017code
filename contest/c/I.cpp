#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

bool check(int n){
	while(n){
		if(n%10 == 4) return 1;
		n/=10;
	}
	return 0;
} 

int main(){
	int T,n,tot=1;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		int cnt = 0;
		for(int i=1;i<=n;i++){
			if(check(i)) continue;
			cnt++;
		}
		printf("Case #%d: %d\n",tot++,cnt);
	}
	return 0;
} 
