#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n,m;

LL t,x,y;

int main(){
	scanf("%d",&n);
	LL tot=0;
	for(int i=1;i<=n;i++){
		cin>>t;
		tot+=t;
	}
	scanf("%d",&m);
	LL sum=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x<=tot&&tot<=y){
			sum=tot;
			break;
		}
		if(tot<x){
			sum=x;
			break;
		}
	}
	if(sum==0) puts("-1");
	else cout<<sum<<endl;
	return 0;
}
