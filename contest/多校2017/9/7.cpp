#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100005
using namespace std;
int v[MAXN],w[MAXN],n,k,ans[MAXN];
struct node{
	double per;
	int id;
}p[MAXN];
bool cmp(const node &a,const node &b){
	return a.per > b.per;
}
bool judge(double mid){
	for(int i=0;i<n;i++){
		p[i].per = (double)v[i] - mid * w[i];
		p[i].id = i;
	}
	sort(p,p+n,cmp);
	double sum = 0;
	for(int i=0;i<k;i++){
		sum += p[i].per;
		ans[i] = p[i].id;
	}
	return sum >= 0;
}
void solve(){
	double l = 0,r = MAXN,mid;
	while(r-l > 1e-6){
		mid = (l + r) / 2;
		if(judge(mid)) l = mid;
		else r = mid;
	}
	for(int i=0;i<k;i++){
		printf("%d",ans[i]+1);
		if(i < k-1){
			printf(" ");
		}
	}
	printf("\n");
}
int main(void){ 
//	freopen("input.txt","r",stdin);
	while(~scanf("%d %d",&n,&k)){
		for(int i=0;i<n;i++){
			scanf("%d %d",&v[i],&w[i]);
		}
		solve();
	}
}
