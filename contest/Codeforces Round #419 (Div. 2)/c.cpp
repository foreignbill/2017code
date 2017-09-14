#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;

int n,m,tot,found,top;
int g[maxn][maxn];

struct node{
	int tp,id,t;
}s[2000000];

void print(int dep,int tot){
	printf("%d\n",tot);
	for(int i=1;i<=dep;i++){
		if(s[i].tp==0){
			for(int c=1;c<=s[i].t;c++)
				printf("row %d\n",s[i].id);
		} else {
			for(int c=1;c<=s[i].t;c++)
				printf("col %d\n",s[i].id);
		}
	}
}

int dfs(int left,int tot){
	if(found) return 0;
	if(left==0){
		found=1;
		print(top,tot);
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(g[i][0]>0){
			top++;
			int t = g[i][0];
			s[top].t=g[i][0];
			g[i][0]=0;
			s[top].tp=0;
			s[top].id=i;
			dfs(left-t*m,tot+t);
			top--;
			g[i][0]=t;
		}
	for(int i=1;i<=m;i++)
		if(g[0][i]>0){
			top++;
			int t = g[0][i];
			s[top].t=g[0][i];
			g[0][i]=0;
			s[top].id=i;
			s[top].tp=1;
			dfs(left-t*n,tot+t);
			top--;
			g[0][i]=t;
		}
}

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);
	tot=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i][1]);
		g[i][0]=g[i][1]; 
		tot+=g[i][1];
		for(int j=2;j<=m;j++){
			scanf("%d",&g[i][j]);
			tot+=g[i][j];
			if(g[i][j]<g[i][0])
				g[i][0]=g[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		g[0][j]=g[1][j];
		for(int i=2;i<=n;i++){
			if(g[i][j]<g[0][j])
				g[0][j]=g[i][j];
		}
	}
	found=0;
	top=0;
	dfs(tot,0);
	if(!found){
		puts("-1");
	}
	return 0;
} 
