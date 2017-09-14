#include <cstdio>
#include <cstring>
#include <iostream>
#include <string> 

#define LL long long
 
using namespace std;

LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
} 

int main(){
	LL x,n;
	while(cin>>x>>n){
		for(LL i=2;i<=n;i++){
			LL c = x % i;
			LL t = gcd(c, i);
			LL ans =  i / t;
			cout<<ans<<endl;
		}
	}
	return 0;
}
