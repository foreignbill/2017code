#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1,1,2,2,-1,-1,-2,-2};
const int dy[] = {2,-2,1,-1,2,-2,1,-1};

bool v[10][10];
int n,m;
int ans = 0;

int count(int x,int y){
	int cnt = 0;
	for(int i=0;i<8;i++){
		int nowx = x+dx[i],nowy = y+dy[i];
		if(nowx<=0||nowx>n||nowy<=0||nowy>m) continue;
		cnt += (v[nowx][nowy]==0) ;
	}
	return cnt;
}

int countnxt(int x,int y){
	for(int i=0;i<8;i++){
		int nowx = x+dx[i];
		int nowy = y+dy[i];
		if(nowx<=0||nowx>n) continue;
		if(nowy<=0||nowy>m) continue;
		if(v[nowx][nowy]) continue;
		if(count(nowx,nowy)<=1) return 0;
	}
	return 1;
}

inline void dfs(int x,int y,int dep){
	if(dep == n * m){
		ans++;
		return ;
	}
	for(int i=0;i<8;i++){
		int nowx = x + dx[i];
		int nowy = y + dy[i];
		if(nowx<=0||nowx>n) continue;
		if(nowy<=0||nowy>m) continue;
		if(v[nowx][nowy]) continue;
		if(dep<n*m-2&&countnxt(nowx,nowy)==0) continue;
		v[nowx][nowy] = 1;
		dfs(nowx,nowy,dep+1);
		v[nowx][nowy] = 0;
	}
}

int main(){
	memset(v,0,sizeof(v));
	cin>>n>>m;
	v[1][1] = 1;
	dfs(1,1,1);
	cout<<ans<<endl;
	return 0;
} 
