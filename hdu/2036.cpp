#include <iostream>
#include <iomanip>

using namespace std;

struct node{
	int x,y; 
}a[1111];

int main(){
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;i++) cin>>a[i].x>>a[i].y;
		double sum=0;
		for(int i=1;i<n-1;i++){
			sum+=(a[0].x*a[i+1].y + a[0].y*a[i].x + a[i+1].x*a[i].y - a[0].x*a[i].y -a[0].y*a[i+1].x -a[i+1].y*a[i].x)/2.0;
		}
		cout<<fixed<<setprecision(1)<<-sum<<endl;
	}
	return 0;
}
