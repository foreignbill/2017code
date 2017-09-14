#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string st;

const int MOD = 1e9+7;

int main(){
	cin>>st;
	int x = 0;
	int ans = 0;
	for(int i = st.size()-1;i>=0;i--){
		if(st[i]=='a'){
			ans = (ans + x) % MOD;
			x = (x + x) % MOD;
		} else {
			x++;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
