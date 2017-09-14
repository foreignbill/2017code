#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int link[100][100],n,x,y,w;
bool v[100];

int dfs(int id){
	for(int i=1;i<=n;i++)
		if(link[id][i]&&!v[i]){
			v[i]=1;
			dfs(i);
			v[i]=0;
		} 
}

int main(){
	/*
	�ڽӾ��� 
	*/
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&w);
		link[x][y]=w;
		link[y][x]=w;//˫��� 
	}//��ͼ 
	
	memset(v,0,sizeof(v));
	v[1] = 1;
	dfs(1); //��1��ʼ���� 
	
	return 0;
}
