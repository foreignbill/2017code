#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int x[2222];

int main(){
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n+n-2;i++)
			cin>>x[i];
		int ans = x[1] + x[2];
		for(int i=2;i<=n-1;i++)
			ans = min(ans,x[i+i-1] + x[i+i]);
		cout<<ans<<endl;
	}
	return 0;
} 
