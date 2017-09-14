#include <bits/stdc++.h>

#define LL long long

using namespace std;

const LL MOD = 1000000007;

int a[20],k;

LL f[22];

LL GCD[22][22];

void dfs(int dep,int left){
	if(left==0){
		f[dep]++;
	}
	for()
}

int main(){
	int n;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			LL t=a[i];
			for(int c=i+1;c<=j;c++)
				t=gcd(a[c],t);
			f[i][j]=t; 
		}
	dfs(0,n);
	return 0;
} 
