#include <bits/stdc++.h>

using namespace std;

int n,k;
int a[10005];
char s[10005];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		getchar();
		gets(s+1);
		int len = strlen(s+1);
		int sumn = 0,suml = 0,sumd = 0;
		for(int i=1;i<=n;i++){
			if(s[i+i-1]=='N') sumn+=a[i];
			else if(s[i+i-1]=='L') suml+=a[i];
			else sumd += a[i];
		}
		if(-sumd-sumn<=k && k<=sumn+suml)
			puts("yes");
		else puts("no");
	}
	return 0;
} 
