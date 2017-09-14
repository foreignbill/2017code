#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	long long x,n,sum;
	cin>>x;
	n=sum=0;
	while(sum<x){
		sum+=n;
		n++;
	}
	n--;
	cout<<n<<endl;
	return 0;
} 
