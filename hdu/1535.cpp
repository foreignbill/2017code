#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m,x,y,w;

struct node{
	int to,w;
	node(int _to,int _w):to(_to),w(_w){	}
};

vector<node> e1[222222],e2[222222];

int dist1[222222],dist2[222222];

class cmp1{
	public:
		bool operator()(int i,int j){
			return (dist1[i]>dist1[j]);
		}
};

class cmp2{
	public:
		bool operator()(int i,int j){
			return (dist2[i]>dist2[j]);
		}
};

priority_queue<int,vector<int> ,cmp1> Q1;
priority_queue<int,vector<int> ,cmp2> Q2;

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			e1[i].clear();
			e2[i].clear();
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&w);
			e1[x].push_back(node(y,w));
			e2[y].push_back(node(x,w));
		}
		memset(dist1,63,sizeof(dist1));
		memset(dist2,63,sizeof(dist2));
		
		dist1[1]=0;
		while(!Q1.empty()) Q1.pop();
		Q1.push(1);
		while(!Q1.empty()){
			int now = Q1.top();Q1.pop();
			for(int i=0;i<e1[now].size();i++){
				node tmp = e1[now][i];
				if(tmp.w+dist1[now]<dist1[tmp.to]){
					dist1[tmp.to]=tmp.w+dist1[now];
					Q1.push(tmp.to);
				}
			}
		}
	
	
		dist2[1]=0;
		while(!Q2.empty()) Q2.pop();
		Q2.push(1);
		while(!Q2.empty()){
			int now = Q2.top();Q2.pop();
			for(int i=0;i<e2[now].size();i++){
				node tmp = e2[now][i];
				if(tmp.w+dist2[now]<dist2[tmp.to]){
					dist2[tmp.to]=tmp.w+dist2[now];
					Q2.push(tmp.to);
				}
			}
		}
		int mn = 0;
		for(int i=2;i<=n;i++) mn += dist1[i]+dist2[i];
		printf("%d\n",mn);
	}
	return 0;
} 
