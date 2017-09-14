#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

double E[101][101];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++)
		for(int j=1;i+j<=n;j++)
			cin>>E[i][i+j];
	if(n==1){
		for(int i=1;i<=m;i++){
			int x;
			scanf("%d",&x);
			if(x==1) puts("1.00000");
			else puts("0.00000");
		}
	}
	if(n==2){
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==0&&y==0){
				puts("0.00000");
			}
			if(x==0&&y==1){
				printf("%.5llf\n",1-E[1][2]);
			}
			if(x==1&&y==0){
				printf("%.5llf\n",E[1][2]);
			}
			if(x==1&&y==1){
				puts("1.00000");
			}
		}
	}
	
	return 0;
} 
