#include <bits/stdc++.h>

using namespace std;

int num[10000010];

int main(){
	num[1]=1;
	num[2]=num[3]=2;
	int id = 3;
	int cur = 1;
	for(int i=4;i<=10000000;){
		for(int j=0;j<num[id];j++,i++)
			num[i]=cur;
		id++;
		if(cur == 1) cur=2;
		else cur = 1;
	} 
	int T,n;
	while(cin>>T){
		while(T--){
			scanf("%d",&n);
			printf("%d\n",num[n]);
		}
	}
	return 0;
} 
