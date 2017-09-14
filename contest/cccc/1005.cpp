#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		long long a,b,c,n;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&n);
		
		int k=n/a+1;
		bool flag=false;
		for (long long i=0;i<k;i++){
			long long l=0,r=(n-i*a)/b,mid;
			
			while (l<=r){
				mid=(l+r)/2;
				long long z=n-i*a-mid*b;
				if (z%c==0) {
					printf("Yes\n");
					flag=true;
					break;
				}
				if (z<0) r=mid-1;
				else l=mid+1;
			}
			if (flag==true) break;
		}
		if (flag==false) printf("No\n");
	}
	return 0;
}
