#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;

string ans,st;

int n,mx;

int main(){
	while(cin>>n){
		mp.clear();
		mx=0;
		for(int i=1;i<=n;i++){
			cin>>st;
			mp[st]++;
			if(mp[st]>mx){
				mx=mp[st];
				ans=st;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
