#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char st[10000];

int a[333];

int main(){
	int T,id;
	cin>>T;
	while(T--){
		scanf("%d",&id);
		for(int i=1;i<=10;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+11);
		printf("%d %d\n",id,a[8]);
	}
	return 0;
} 
