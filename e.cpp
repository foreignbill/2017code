#include <cstdio>
#include <algorithm>
#include <iostream>

#define LL long long

using namespace std;

int n,m,C;

int a[100010];

int main(){
	while(cin>>n>>m>>C){
		a[1]=0;n++;
		for(int i=2;i<=n;i++){
			scanf("%d",a+i);
			a[i] += a[i-1];
		}
		sort(a+1,a+1+n);
		LL ans = 0;
		for(int i=1;i<=m;i++){
			if(abs(a[i] - a[n-i+1])<C) break;
			ans += (LL)abs(a[i] - a[n-i+1]) - C;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
