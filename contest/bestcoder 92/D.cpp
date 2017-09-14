#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct node{
	int l,r;
}info[10005];

int main(){
	int T,n,m,top;
	scanf("%d",&T);
	while(T--){
		top=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			top++;
			scanf("%d%d",&info[top].l,info[top].r);
			if(info[top].l==info[top-1].r+1){
				top--;
				info[top].r=info[top+1].r;
			}
		}
	}
	return 0;
} 
