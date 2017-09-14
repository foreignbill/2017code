#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int T,n,a;
	cin>>T;
	while(T--){
		cin>>n;
		int cnt = 1;
		for(int i=2;i<=n;i++){
			cin>>a;
			if(a == 2 || cnt == 0){
				cnt++;
			} else {
				cnt--;
			}
		}
		if(cnt) puts("No");
		else puts("Yes");
	} 
	
	return 0;
} 

