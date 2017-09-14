#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int n;

queue<string> Q;
map<string,int> mp;

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int ans = 0;
		string tp,st;
		mp.clear();
		while(!Q.empty()) Q.pop();
		for(int i=1;i<=n;i++){
			cin>>tp>>st;
			if(tp == "in"){
				Q.push(st);
			} else {
				while(mp[Q.front()] == 1){
					Q.pop();
				}
				if(st == Q.front())
					ans++;
				mp[st] = 1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
