#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n;
double k;

const double eps = 1e-7;

double info[111111];

int main(){
	int T;
	cin>>T;
	for(int id=1;id<=T;id++){
		cin>>n>>k;
		double l,r;
		cin>>info[1];
		l=r=info[1];
		for(int i=2;i<=n;i++){
			cin>>info[i];
			if(info[i]<l) l=info[i];
			if(info[i]>r) r=info[i];
		}
		double ans=l;
		while(r-l>eps){
			double mid = (l+r)/2;
			double x1 = 0 , x2 = 0;
			for(int i=1;i<=n;i++){
				if(info[i]<mid) x1 += mid-info[i];
				if(info[i]>mid) x2 += info[i]-mid; 
			}
			if(x2 * (1-k) > x1){
				ans = mid;
				l = mid + eps;
			} else r = mid - eps;
		}
		printf("Case #%d: %.6lf\n",id,ans);
	}
	return 0;
} 
