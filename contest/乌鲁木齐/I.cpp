#include <bits/stdc++.h>

using namespace std;

struct node{
	const int maxn = 505;
	int a[maxn][maxn];
	int n;
	void init(){
		
	}
};

int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		node A;
		A.n=n;
		A.init();
		A.print();
	}
	return 0;
} 
