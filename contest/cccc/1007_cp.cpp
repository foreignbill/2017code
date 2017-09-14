#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define LL long long 

using namespace std;

struct node{
	int h,a;
}info[111];

bool v[111];
int num[111];
LL n,att,Min,allattack;
	
LL calc(int allattack){
	LL ans = 0;
	
	for(int i=1;i<=n;i++){
		LL t1;
		if(info[num[i]].h%att){
			t1=info[num[i]].h/att;
		} else {
			t1=info[num[i]].h/att-1;
		}
		ans += t1 * allattack + allattack - info[num[i]].a;
		allattack -= info[num[i]].a;
	}
	return ans;
} 

int dfs(int dep){
	if(dep==n+1){
		LL hurt = calc(allattack);
		if(hurt<Min) Min=hurt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		num[dep]=i;
		dfs(dep+1);
		v[i]=0;
	}
}

int main(){
	freopen("input.txt","r",stdin);
	while(cin>>n>>att){
		allattack = 0;
		for(int i=1;i<=n;i++){
			cin>>info[i].h>>info[i].a;
			allattack+=info[i].a;
		}
		Min=LONG_LONG_MAX;
		memset(v,0,sizeof(v));
		dfs(1);
		cout<<Min<<endl;
	}
	
	return 0;
}
