#include <cstdio>
#include <algorithm>
#include <iostream> 
using namespace std;
struct node{
	int val,cnt;
}a[30000];
int c[30000];
bool comp(node a,node b){return a.val<b.val;}
int main(){
	int T,n,top;
	long long ans,now,tmp;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i].val,&a[i].cnt);
		sort(a+1,a+1+n,comp);
		top = 0;
		ans = 0;
		now = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].cnt;j++){
				c[++top] = a[i].val;
				ans += a[i].val*top;
				now += a[i].val;
			}
		}
		tmp = ans;
		for(int i=1;i<=top;i++){
			if(c[i]>=0) break;
			tmp -= now;
			now -= c[i];
			if(tmp > ans) ans = tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
