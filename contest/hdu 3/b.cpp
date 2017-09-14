#include <iostream>
#include <cstring>

using namespace std;

int g[1111],mx,a,b;

int main(){
	int i,j,m,sum,q;
	int n;
	while(scanf("%d%d",&n,&m),n||m){
		memset(g,0,sizeof(g));
		mx=0;
		for(i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			g[a]++;g[b]++; 
			if(g[a]>mx) mx=g[a];
			if(g[b]>mx) mx=g[b];
		}
		printf("%d\n",mx);
	}
	return 0;
}
