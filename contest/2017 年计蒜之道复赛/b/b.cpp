#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int g[333][333];

int xa,ya,x2,y2,n,m;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void solve(int xa,int ya,int x2,int y2,int i){
	if(xa<=x2&&ya<=y2){
		int x=(x2-xa);
		int y=(y2-ya);
		int delta=gcd(x,y);
		int deltax=x/delta;
		int deltay=y/delta;
		for(int x=xa,y=ya;x<=x2&&y<=y2;x+=deltax,y+=deltay)
			g[x][y]=i;
		return;
	}
	if(xa>x2&&ya>y2){
		swap(xa,x2);swap(ya,y2);
		int x=(x2-xa);
		int y=(y2-ya);
		int delta=gcd(x,y);
		int deltax=x/delta;
		int deltay=y/delta;
		for(int x=xa,y=ya;x<=x2&&y<=y2;x+=deltax,y+=deltay)
			g[x][y]=i;
		return;
	}
	if(xa<=x2&&ya>y2){
		int x=(x2-xa);
		int y=(ya-y2);
		int delta=gcd(x,y);
		int deltax=x/delta;
		int deltay=y/delta;
		for(int x=xa,y=ya;x<=x2&&y>=y2;x+=deltax,y-=deltay)
			g[x][y]=i;
		return;
	}
	if(xa>x2&&ya<=y2){
		swap(xa,x2);swap(ya,y2);
		int x=(x2-xa);
		int y=(ya-y2);
		int delta=gcd(x,y);
		int deltax=x/delta;
		int deltay=y/delta;
		for(int x=xa,y=ya;x<=x2&&y>=y2;x+=deltax,y-=deltay)
			g[x][y]=i;
		return;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&xa,&ya,&x2,&y2);
		solve(xa,ya,x2,y2,i); 
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",g[x][y]);
	}
	return 0;
} 
