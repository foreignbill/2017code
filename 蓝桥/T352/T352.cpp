#include <cstdio>
#include <cstring>

bool v[10];
int data[10];
int cnt,n;

int dfs(int dep){
	if(dep==10){
		cnt++;
		if(cnt==n){
			for(int i=0;i<=9;i++){
				putchar(data[i]+48);
			}
			puts("");
		}
		return 0;
	}
	for(int i=0;i<=9;i++){
		if(v[i]) continue;
		v[i] = true;
		data[dep] = i;
		dfs(dep+1);
		v[i] = false;
	}
}

int main(){
	cnt=0;
	scanf("%d",&n);
	memset(v,0,sizeof(v));
	dfs(0);
	return 0;
} 
