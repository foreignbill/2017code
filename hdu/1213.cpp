#include <cstdio>
#include <iostream>

using namespace std;

int f[1111],n,m,u,v;

int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
} 

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			int h1 = find(u);
			int h2 = find(v);
			f[h1]=h2;
		}
		int ans = 0;
		for(int i=1;i<=n;i++) ans += (f[i]==i);
		printf("%d\n",ans);
	}
	return 0;
} 
