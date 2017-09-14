#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct Edge{
	int v,w,nxt;
}e[222222];

int head[2222];

int dist[2222];

int n,k,t,top;

char type;

map<string,int> mp;

string st[11];

void addedge(int u,int v,int w){
	e[++top].v = v;
	e[top].w = w;
	e[top].nxt = head[u];
	head[u] = top;
	
	e[++top].v = u;
	e[top].w = w;
	e[top].nxt = head[v];
	head[v] = top;
}

class cmp{public:bool operator()(int i,int j){return (dist[i] > dist[j]);}};

priority_queue<int,vector<int>,cmp> Q;

int main(){
	int T;
	cin>>T;
	for(int id=1;id<=T;id++){
		mp.clear();
		t=0;
		top=0;
		memset(head,0,sizeof(head));
		cin>>n;
		for(int cnt=1;cnt<=n;cnt++){
			cin>>type>>k;
			for(int i=1;i<=k;i++){
				cin>>st[i];
				if(!mp[st[i]]){
					t++;
					mp[st[i]]=t;
				}
			}
			if(type=='A'){
				for(int i=1;i<k;i++)
					for(int j=i+1;j<=k;j++){
						addedge(mp[st[i]],mp[st[j]],2);
					}
			}
			if(type=='B'){
				for(int i=1;i<k;i++)
					addedge(mp[st[i]] ,mp[st[i+1]] ,0);
			}
		}
		memset(dist,63,sizeof(dist));
		string str,edr;
		cin>>str>>edr;
		int start,end;
		start=mp[str];end=mp[edr];
		dist[start]=0;
		Q.push(start);
		while(!Q.empty()){
			int now = Q.top(); Q.pop();
			for(int k=head[now];k;k=e[k].nxt){
				if(e[k].w+dist[now]<dist[e[k].v]){
					dist[e[k].v]=e[k].w+dist[now];
					Q.push(e[k].v);
				}
			}
		}
		printf("Case #%d: %d\n",id,dist[end]);
	}
	return 0;
} 
