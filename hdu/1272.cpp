#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int x,y;

int f[111111],edg;

bool v[111111];

int find(int x){
	if(x==f[x]) return x;
	return f[x] = find(f[x]);
}

int main(){
	while(scanf("%d%d",&x,&y),x+1||y+1){
		if(x==0 && y==0){
			puts("Yes");
			continue;
		}
		edg = 0;
		for(int i=1;i<=100000;i++) f[i]=i;
		memset(v,0,sizeof(v));
		bool flag = 1;
		int h1 = find(x); int h2 = find(y);
		v[x]=v[y]=1;
		if(h1 == h2) flag = 0;
		if(h1 != h2) edg++;
		f[h1] = h2;
		while(scanf("%d%d",&x,&y),x||y){
			int h1 = find(x); int h2 = find(y);
			if(h1 != h2) edg++;
			v[x]=v[y]=1;
			if(h1 == h2) flag = 0;
			f[h1] = h2;
		}
		int cnt = 0;
		for(int i=1;i<=100000;i++){
			cnt += v[i];
		}
		if(!flag) puts("No");
		else{
			if(cnt == edg+1) puts("Yes");
			else puts("No");
		}
	}
	return 0;
} 
