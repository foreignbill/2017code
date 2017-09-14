#include <cstdio>

using namespace std;

bool v[100]={0};
int  a[100],n=3,ans=0;
	
int dfs(int dep){
	if(dep==n+1){
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		puts("");
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1,a[dep]=i;
		dfs(dep+1);
		v[i]=0;
	}
}

int main(){
	dfs(1);
	return 0;
}
