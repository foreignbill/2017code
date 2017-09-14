#include <cstdio>
#include <cstring>

using namespace std;

struct node{
	int x,y,w;
}edge[10001];

int x,y,w,n,m;

int main(){
	scanf("%d%d",&n,&m);//m == the sum of edges
	int top = 0;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&w);
		edge[++top].x = x;
		edge[top].y = y;
		edge[top].w = w;
	}
	
	return 0;
} 
