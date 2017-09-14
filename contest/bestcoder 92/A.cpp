#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	string st;
	int cost;
}info[1005];

bool comp(node A,node B){
	if(A.st==B.st){
		return A.cost>B.cost;
	}
	return A.st<B.st;
}

int main(){
	int T,n,x;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>info[i].st>>info[i].cost;
		}
		sort(info+1,info+1+n,comp);
		int ans = 0;
		for(int i=1;i<=n;i++){
			if(info[i].st!=info[i-1].st) ans+=info[i].cost;
			else if(info[i].st!=info[i-2].st) ans+=info[i].cost;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
