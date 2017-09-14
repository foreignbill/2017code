#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#define N 100005
#define M 500025
using namespace std;
struct node {
	int x,y,id;
} b[M];
int c[N],ans[M],a[N];
map<int ,int >ma;
bool cmp(node a,node b) {
	return a.y<b.y;
}
int lowbit(int x) {
	return x&(-x);
}
void update(int x,int val) {
	while(x<=N) {
		c[x]+=val;
		x+=lowbit(x);
	}
}
int sum(int x) {
	int s=0;
	while(x) {
		s+=c[x];
		x-=lowbit(x);
	}
	return s;
}
int main() {
	int n,i,m,pre,j;
	//freopen("a.txt","r",stdin);
	while(scanf("%d",&n)!=EOF) {
		for(i=1; i<=n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&m);
		for(i=0; i<m; i++) {
			scanf("%d%d",&b[i].x,&b[i].y);
			b[i].id=i;
		}
		sort(b,b+m,cmp);
		pre=1;			
		memset(c,0,sizeof(c));
		for(i=0; i<m; i++) {
			for(j=pre; j<=b[i].y; j++) {
				if(ma.find(a[j])==ma.end())
					update(j,1);
				else {
					update(ma[a[j]],-1);
					update(j,1);
				}
				ma[a[j]]=j;
			}
			ans[b[i].id]=sum(b[i].y)-sum(b[i].x-1);
			pre=b[i].y+1;
		} 
		for(i=0; i<m; i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}
