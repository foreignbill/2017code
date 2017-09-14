#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int n,m,r;

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m>>r;
		if(n>=r+r && m>=r+r){
			puts("forever97.");
		} else {
			puts("pikapikachu>.<");
		}
	}
	return 0;
} 
