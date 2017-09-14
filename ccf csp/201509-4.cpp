#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std; 

#define LL long long 

const int MAXN = 10010;
const int MAXM = 100010;

struct Edge{
	int to, next;
}edge[MAXM];

int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],Belong[MAXN];
int Index,top;
int scc;
bool Instack[MAXN];
int num[MAXN];

void addedge(int u,int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u]=tot++;
}

void Tarjan(int u){
	int v;
	Low[u] = DFN[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = 1;
	for(int i=head[u];i!=-1;i=edge[i].next){
		v = edge[i].to;
		if( !DFN[v] ){
			Tarjan(v);
			if(Low[u]>Low[v]) Low[u]=Low[v];
		} else if(Instack[v] && Low[u]>DFN[v])
					Low[u]=DFN[v];
	}
	if(Low[u]==DFN[u]){
		scc++;
		do{
			v=Stack[--top];
			Instack[v]=0;
			Belong[v]=scc;
			num[scc]++;
		}while(v!=u);
	}
}

void solve(int N){
	memset(DFN,0,sizeof(DFN));
	memset(Instack,0,sizeof(Instack));
	memset(num,0,sizeof(num));
	Index = scc = top = 0;
	for(int i=1;i<=N;i++)
		if(!DFN[i])
			Tarjan(i);
}

void init(){
	tot = 0;
	memset(head,-1,sizeof(head));	
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
	solve(n);
	LL ans = 0;
	for(int i=1;i<=scc;i++)
		ans +=(LL)num[i]*(num[i]-1)/2;
	cout<<ans<<endl;
	return 0;
}
