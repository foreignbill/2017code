#include<cstdio>
#include<algorithm>
#include<cstring>

using std::sort;

int f[600];
struct edge{
	int from;
	int to;
	int side;
}e[5100];

bool cmp(edge a, edge b){
	return a.side<b.side;
}
void init(int n){
	for(int i=1;i<=n;i++) f[i]=i;
}

int find(int x){
	return f[x]=(x==f[x])?x:find(f[x]);
}

void unite(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b) return ;
	f[a]=b;
}

int judge(int a, int b){
	return find(a)==find(b);
}

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		init(N);
		int i,j;
		int a,b,t=1;
		for(i=1;i<=N;i++){
	 		for(j=1;j<=N;j++)
			{
	 			scanf("%d",&a);
				if(i<j){
					e[t].from=i;
					e[t].to=j;
					e[t++].side=a;
				}
			}
		}
		int Q;
		sort(e+1,e+t,cmp);
		scanf("%d",&Q);
		for(j=1;j<=Q;j++){
			scanf("%d%d",&a,&b);
			unite(a,b);
		}
		int tot=0;
		for(i=1;i<=t-1;i++){
			if( !judge(e[i].from,e[i].to) ){
				tot+=e[i].side;
				unite(e[i].from,e[i].to);
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
