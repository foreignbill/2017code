#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
	int x,y;
}info[11111];

struct edge{
	int f,r;
	double w;
}e[11111];

double get(int x1,int y1,int x2,int y2){
	double x = (x2 - x1) * (x2 - x1);
	double y = (y2 - y1) * (y2 - y1);
	return sqrt(x + y);
}

bool comp(edge A,edge B){
	return A.w<B.w;
}

int f[11111];

int find(int x){
	if(x==f[x]) return x;
	return f[x] = find(f[x]);
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>info[i].x>>info[i].y;
		int tot = 0;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++){
				double ww = get(info[i].x,info[i].y,info[j].x,info[j].y);
				if(ww<10)continue;if(ww>1000)continue;
				e[++tot].f=i;
				e[tot].r=j;
				e[tot].w=ww;
			}
		sort(e+1,e+1+tot,comp);
		for(int i=1;i<=n;i++) f[i]=i;
		int j=0;
		double ans = 0;
		for(int i=1;i<=tot;i++){
			int h1 = find(e[i].f);
			int h2 = find(e[i].r);
			if(h1 != h2){
				j++;
				f[h1]=h2;
				ans += e[i].w;
			}
			if(j == n-1){
				break;
			}
		}
		if(j==n-1) printf("%.1llf\n",100.0*ans);
		else printf("oh!\n");
	}
	return 0;
}
