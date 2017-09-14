#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int f[111111];

bool flag[111111];

struct node{
	int x,y,w;
}info[111111];

bool comp(node A,node B){
	return A.w>B.w;
}

int find(int x){
	if( x == f[x] ) return x;
	return f[x] = find(f[x]);
}

int main(){
	while(scanf("%d%d",&n,&m),n||m){
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&info[i].x,&info[i].y,&info[i].w);
		}
		memset(flag,0,sizeof(flag));
		for(int i=0;i<=n;i++) f[i]=i;
		sort(info+1,info+1+m,comp);
		int j = 0;
		int ans = 0;
		for(int i=1;i<=m;i++){
			int h1 = find(info[i].x);
			int h2 = find(info[i].y);
			if(flag[h1] && flag[h2]) continue;
			ans += info[i].w;
			f[h1] = h2;
			if(flag[h1] || flag[h2] || h1 == h2)
				flag[h2]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
} 
