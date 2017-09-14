#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int exgcd(int a,int b,int &x,int &y){
	if(!b) return x=1,y=0,a;
	int d=exgcd(b,a%b,x,y),t=x;
	return x=y,y=t-a/b*y,d;
}

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

int main(){
	int T,tot=1,A,B;
	cin>>T;
	while(T--){
		scanf("%d%d",&A,&B);
		int GCD=gcd(A,B);
		//A/=GCD;B/=GCD;
		int x,y;
		exgcd(A,B,x,y);
		x %= B;
		if(x>0) x-=B;
		int t=-x;
		cout<<t<<endl;
		long long ans = (long long)(t*A+1)/B;
		int com = gcd(ans,t);
		ans /= com,t /= com;
		if(t!=1) printf("Case #%d: %d/%d\n",tot++,ans,t);
		else printf("Case #%d: %d\n",tot++,ans);
	}
	return 0;
} 
