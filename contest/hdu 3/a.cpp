#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

long long c[20][20];

void printc(){
	c[0][0]=1;
	for(int i=1;i<=15;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++) c[i][j] = c[i-1][j-1] + c[i-1][j];
	}
}

int main(){
	printc();
	long long n,m,k;
	while(cin>>n>>m>>k,n||m||k){
		if(n - m*k<0) puts("0");
		else{
			long long ans=1;
			for(int i=0;i<m;i++) ans*=c[n - i*k][k];
			n-=m*k;
			for(int i=0;i<n;i++) ans*=m;
			cout<<ans<<endl; 
		}
	}
	
	return 0;
} 
