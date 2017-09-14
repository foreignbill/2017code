#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int N,K;
int a[5555];
bool v[5555];
int tp;

bool dfs(int x,int sum){
	if(x+sum>=K) return 1; 
	for(int i=tp;i>=1;i--){
		if(v[i]) continue;
		if(sum+a[i]>=K) continue;
		v[i]=1;
		//bool pan = dfs(x,sum+a[i]);
		//if(pan) return 1;
		return dfs(x,sum+a[i]);
		v[i]=0;
	}
	return 0;
}

int main(){
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+N);
	
	int count = N;
	
	for(tp=N;a[tp]>K;tp--);
	
	int tope = a[tp];
	
	for(int i=N;i>=1;i--){
		if(a[i]>=K){
			count--;
			continue;
		}
		if(i<tp){ 
			if(a[i]+tope>=K){
				count--;
				continue;
			}
			if(a[i]+tope<K) tope=a[i]+tope; 
		} 
		memset(v,0,sizeof(v));
		v[i]=1;
		if(dfs(a[i],0)) count--;
	}
	printf("%d\n",count);
	return 0;
} 
