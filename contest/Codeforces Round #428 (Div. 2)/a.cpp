#include <bits/stdc++.h>
using namespace std; 
int n,k;
int a[222];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) 
		scanf("%d",&a[i]);
	int x=0,y=0;
	for (int i=0;i<n;i++){
		x+=a[i];
		y++;
		if(x>=8){
			x-=8;
			k-=8;
		}else{
			k-=x;
			x=0;
		}
		if(k<=0){
			cout<<y<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}
