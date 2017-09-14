#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int x,y,w;
}e[100005];

int binc[100005];

bool comp(node A,node B){
	return A.w<B.w;
}

int find(int x){
	if(binc[x]==-1) return x;
	else return binc[x]=find(binc[x]);
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	memset(binc,-1,sizeof(binc));
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	sort(e+1,e+1+m,comp);
	
	int ans = 0,picked=0;
	for(int i = 1;i <= m;i++){
		int t1 = find(e[i].x);
		int t2 = find(e[i].y);
		if(t1!=t2){
			ans += e[i].w;
			binc[t1]=t2;
			picked++;
		}
		if(picked==n-1) break;
	}
	printf("%d\n",ans);
	return 0;
}
