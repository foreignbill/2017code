#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

struct node {
	int x,y,steps,num;
}Q[1000000]; 

int map[33][33];
int v[33][33][33];
int n,m,k,t,stx,sty,edx,edy;

int bfs(){
	int f=1,r=1;
	while(f<=r){
		if(Q[f].steps>t) return -1;
		if(Q[f].x==edx&&Q[f].y==edy) return Q[f].steps;
		int nx=Q[f].x,ny=Q[f].y;
		for(int i=0;i<4;i++){
			int ax=nx+dx[i];
			int ay=ny+dy[i];
			if(ax<=0||ax>n) continue;
			if(ay<=0||ay>m) continue;
			if(map[ax][ay]==1) continue;
			if(v[ax][ay][Q[f].num]) continue;
			v[ax][ay][Q[f].num]=1;
			r++;
			Q[r].x=ax;
			Q[r].y=ay;
			Q[r].steps=Q[f].steps+1;
			Q[r].num=Q[f].num; 
		}
		if(Q[f].num>0){
			
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++){
					int ax=nx+dx[i]+dx[j];
					int ay=ny+dy[i]+dy[j];
					if(ax<=0||ax>n) continue;
					if(ay<=0||ay>m) continue;
					if(map[ax][ay]==1) continue;
					if(v[ax][ay][Q[f].num-1]) continue;
					v[ax][ay][Q[f].num-1]=1;
					r++;
					Q[r].x=ax;
					Q[r].y=ay;
					Q[r].steps=Q[f].steps+1;
					Q[r].num=Q[f].num-1; 					
				}
		}
		f++; 
	}
	return -1;
}

int main(){
	freopen("input.txt","r",stdin);
	char ch;
	while(scanf("%d%d%d%d",&n,&m,&k,&t),n||m||k||t){
		getchar();
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=m;j++){
				ch=getchar();
				if(ch=='#') map[i][j]=1;
				if(ch=='.') map[i][j]=0;
				if(ch=='@'){
					map[i][j]=0;
					stx=i;
					sty=j;
				}
				if(ch=='X'){
					map[i][j]=0;
					edx=i;
					edy=j;
				}
			}
			getchar();
		}
		Q[1].x=stx;Q[1].y=sty;Q[1].steps=0;Q[1].num=k;
		memset(v,0,sizeof(v));
		v[stx][sty][k]=1;
		int ans = bfs();
		if(ans==-1 || ans > t) puts("No");
		else puts("Yes");
	}
	
	return 0;
}
