#include <bits/stdc++.h>

using namespace std;

string st,key; 

map<char,map<char,char> > mp;

void init(){
	mp.clear();
	for(char i='a';i<='z';i++)
		for(char j='a';j<='z';j++)
			mp[i][j]=(i+j-'a'-'a')%26+'a';
}

int main(){
	init();
	while(cin>>st>>key){
		int len=key.size();
		for(int i=0;i<st.size();i++){
			cout<<mp[ st[i] ][ key[i%len] ];
		}
		cout<<endl;
	}
	return 0;
} 
