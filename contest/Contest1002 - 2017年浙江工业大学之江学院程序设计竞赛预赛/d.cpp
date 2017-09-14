#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8; 

double Y; 

int main(){
	while(~scanf("%lf",&Y)){
		if(Y<9 || Y>6579){
			puts("No solution!");
			continue; 
		}
		double l=0.0,r=10.0;
		double ans=-1;
		while(l<=r){
			double x=(l+r)/2.0;
			if(6*x*x*x+5*x*x+7*x+9<=Y){
				ans=x;
				l=x+eps;
			} else {
				r=x-eps;
			}
		}
		if(Y==9) puts("0.0000");
		else if(Y==6579) puts("10.0000"); 
		else if(ans==-1) puts("No solution!");
		else printf("%.4lf\n",ans);
	}
	return 0;
} 
