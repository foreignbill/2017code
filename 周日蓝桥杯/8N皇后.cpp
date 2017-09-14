#include <cstdio>
#include <cstring>

#define base 10

using namespace std;

bool col[10],rz[21],rf[21];

int point[10][10],score=0;

int dfs(int dep,int p){
	if(dep==9){
		if(p>score) score=p;
		return 0;
	}
	for(int i=1;i<=8;i++){
		if(col[i]) continue;
		if(rz[i-dep+base]) continue;
		if(rf[dep+i]) continue;
		col[i]=rz[i-dep+base]=rf[dep+i]=1;
		dfs(dep+1,p+point[dep][i]);
		col[i]=rz[i-dep+base]=rf[dep+i]=0;
	}
}

int main(){
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			scanf("%d",&point[i][j]);
	memset(col,0,sizeof(col));
	memset(rz,0,sizeof(rz));
	memset(rf,0,sizeof(rf));
	dfs(1,0);
	printf("%d\n",score);
	return 0;
} 
