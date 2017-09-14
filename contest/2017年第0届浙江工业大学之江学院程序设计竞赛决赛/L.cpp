#include <bits/stdc++.h>

using namespace std;

int n,m; 

void init(){
	for(int i=1;i<1000;i++)
		for(int j=i+1;j<=1000;j++)
			Add(j,(i*i+j*j)%(i*j));
}

int main(){
	init();
	while(~scanf("%d%d",&n,&m)){
		
	}
	return 0;
} 
