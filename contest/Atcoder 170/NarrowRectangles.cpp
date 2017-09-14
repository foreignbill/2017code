#include <cstdio> 
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n,m;
	int a[11111];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++) printf("%d\n",a[i]);
	
	return 0;
}
