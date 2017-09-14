#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

#define LL long long
 
using namespace std;

LL n,attack,Min,allattack;
LL h[111],a[111];
bool v[111];

int dfs(int dep,LL hurt,int allattack){
	if(dep==n+1){
		if(hurt<Min) Min=hurt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		LL t1,t2;
		if(h[i]%attack)	t1 = h[i]/attack;
		else t1 = h[i]/attack - 1;
		dfs(dep+1, hurt + t1 * allattack + allattack - a[i], allattack-a[i] );
		v[i]=0;
	}
}

int main(){
	while(~scanf("%lld%lld",&n,&attack)){
		allattack=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",h+i,a+i);
			allattack+=a[i];
		}
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i]<a[j]){
					swap(a[i],a[j]);
					swap(h[i],h[j]);
				}
		
		memset(v,0,sizeof(v));
		Min=INT_MAX;
		dfs(1,0,allattack);
		printf("%lld\n",Min);
	}
	return 0;
} 
