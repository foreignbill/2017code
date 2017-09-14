#include <bits/stdc++.h>

#define LL long long

using namespace std;

int a,b,n,even,odd;

LL C[41][41];

void init(){
	C[0][0]=1;
	for(int i=1;i<=40;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}

int main(){
	init();
	while(cin>>a>>b>>n){
		odd = (b-a)/2 + ((a%2) || (b%2));
		even = (b-a)/2 + ((a%2==0) || (b%2==0));
		LL ans = 0LL;
		for(int i=1;i<=odd&&i<=n;i+=2){
			ans += C[even][n-i]*C[odd][i]; 
		}
		cout<<ans<<endl;
	}
	return 0;
} 
