#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double PI = atan(1.0)*4.0;

struct node{
	ll x,y,s;
	double thi;
}info[50005],YUP[50005],YDOWN[50005];

ll presum[50005];

double calc(int x,int y){
	if(x==0 && y>0) return PI*0.5;
	if(x==0 && y<0) return PI*1.5;
	double t = atan2(x,y);
	if(t<0) return t+PI*2.0;
	return t;
}

bool cmp(node A,node B){
	return A.thi<B.thi;
}

int main(){
	int T,n;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		memset(presum,0,sizeof presum);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&info[i].x,&info[i].y,&info[i].s);
			info[i].thi = calc(info[i].x,info[i].y);
		}
		sort(info+1,info+1+n,cmp);
		int c = 1;
		int top1 = 0,top2 = 0;
		for(;c<=n;c++){
			if(info[c].y>=0){
				top1++;
				YUP[top1]=info[c];
			}
		}
		for(;c<=n;c++){
			if(info[c].y<0){
				top2++;
				YDOWN[top2]=info[c];
			}
		}
		for(int i=1;i<=n;i++)
			presum[i] += presum[i-1];
		ll allsum = presum[n];
		int f = 1,r = 1;
		ll sum = 0;
		ll ans = -INT_MAX;
		
	}
	return 0;
} 
