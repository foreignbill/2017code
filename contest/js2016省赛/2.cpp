#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n,x,top;

int p[11111];

void dfs(int id){
	if(id>n) return;
	if(id*2>n){
		p[++top]=id;
		return;
	}
	dfs(id*2);
	p[++top]=id;
	dfs(id*2+1);
}

int main(){
	int T;
	cin>>T;
	for(int id=1;id<=T;id++){
		cin>>n>>x;
		top=0;
		dfs(1);
		printf("Case #%d: %d\n",id,p[x]);
	}
	return 0; 
} 
