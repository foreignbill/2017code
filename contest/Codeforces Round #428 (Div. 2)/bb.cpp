#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 5;
int a[maxn];
int n, k;
int main() {
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++)
		scanf("%d",a+i);
	int xx=n, yy=2*n;
	for(int i=0;i<k;i++){
		int d=min(a[i]/4,xx);
		xx-=d;
		a[i] -= 4*d;
	}
	yy+=xx;
	for(int i=0;i<k;i++){
		int d=min(a[i]/2,yy);
		yy-=d;
		a[i]-=2*d;
	}
	int c=yy+xx;
	for(int i=0;i<k;i++)
		c-=a[i];
	if(c>=0) puts("YES");
	else puts("NO");
	return 0;
}
