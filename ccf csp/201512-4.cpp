#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
bool v[10001][10001];
bool vis[10001]={0};
int du[10001];
int num_odd,x,y;

int ans[10001],top=0;
struct node{
	int s,x,y;
}info[100001];

vector<int> e[10001];

void dfs(int id){
	vis[id]=1;
	for(int i=0;i<e[id].size();i++){
		int ed=e[id][i];
		if(v[id][ed]==0) continue;
		v[id][ed]=v[ed][id]=0;
		dfs(ed);
	}
	ans[++top]=id;
}

bool comp(node A,node B){
	return A.s<B.s;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) e[i].clear();
	memset(v,0,sizeof(v));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&info[i].x,&info[i].y);
		info[i].s=info[i].x+info[i].y;
		du[info[i].x]++;du[info[i].y]++;
		v[info[i].x][info[i].y]=v[info[i].y][info[i].x]=1;
	}
	sort(info+1,info+1+m,comp);
	for(int i=1;i<=m;i++){
		e[info[i].x].push_back(info[i].y);
		e[info[i].y].push_back(info[i].x);
	}
	num_odd=0;
	for(int i=1;i<=n;i++){
		if(du[i]%2) num_odd++;
	}
	bool noans=false;
	if(num_odd!=0&&num_odd!=2){
		puts("-1");
		noans=true;
	}
	if(num_odd==2){
		if(du[1]%2==0){
			puts("-1");
			noans=true;
		}
	}
	dfs(1);
	bool pan=false;
	for(int i=1;i<=n;i++) if(!vis[i]) pan=true;
	if(pan){
		puts("-1");
		noans=true;
	}
	if(noans) return 0;
	for(int i=top;i>1;i--) printf("%d ",ans[i]);
	printf("%d\n",ans[1]); 
	return 0;
} 
