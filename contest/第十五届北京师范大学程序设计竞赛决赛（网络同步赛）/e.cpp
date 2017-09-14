#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const long double pi = 3.1415926535897932384626434;

const double eps = 1e-7;

long double a[3];

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>a[0]>>a[1]>>a[2];
		a[0]*=10000.0;a[1]*=10000.0;a[2]*=10000.0;
		sort(a,a+3);
		long double ans = a[1]*a[1] + (a[2] - a[1])*(a[2] - a[1]);
		ans = ans * pi;
		printf("%.12Lf\n",ans / 100000000);
	}
	return 0;
} 
