#include <bits/stdc++.h>

using namespace std;

double a[100]; 
double s[100];
double mid,mx;
bool v[100];
int n;

bool cmp(double a,double b){
	return a<b;
}

inline bool dfs(int id,double now,double m){
	if(now>mid) return 0;
	if(now<=mid && now>m) return 1;
	if(now+s[id]<m) return 0;
	if(now+a[id]>mid) return 0;
	if(id==n+1){
		return 0;
	}
	bool ok=dfs(id+1,now+a[id],m);
	if(ok) return 1;
	ok|=dfs(id+1,now,m);
	return ok;
}

int main(){
	while(~scanf("%d",&n)){
		mid=0;
		for(int i=1;i<=n;i++){
			scanf("%lf",a+i);
			mid+=a[i];
		}
		mid/=2.0;
		sort(a+1,a+1+n,cmp);
		for(int i=n;i>=1;i--) s[i]=s[i+1]+a[i];
		memset(v,0,sizeof(v));
		double l=-0.0001,r=mid+0.0001,ans;
		while(l<=r){
			double m=(l+r)/2.0;
			bool ok = dfs(1,0.0,m);
			if(ok){
				l=m+0.0001;
				ans=m;
			} else {
				r=m-0.0001;
			}
		}
		printf("%.2lf\n",mid*2-ans*2);
	}
	return 0;
}
