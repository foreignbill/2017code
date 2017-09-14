#include <bits/stdc++.h>

#define LL long long 

using namespace std;

int a[100005];

LL C3(LL n){
	LL tmp = n*(n-1)*(n-2);
	tmp/=6;
	return tmp;
}

LL C2(LL n){
	LL tmp = n*(n-1);
	tmp/=2;
	return tmp;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	LL ans;
	if(a[1]==a[2]&&a[2]<a[3]){
		LL k=3; 
		for(LL i=4;i<=n;i++)
			if(a[i]==a[3])
				k=i;
		ans=k-2;
	}
	if(a[1]==a[2]&&a[2]==a[3]){
		LL k=3; 
		for(LL i=4;i<=n;i++)
			if(a[i]==a[3])
				k=i;
		ans=C3(k);		
	}
	if(a[1]<a[2]&&a[2]==a[3]){
		LL k=3; 
		for(LL i=4;i<=n;i++)
			if(a[i]==a[3])
				k=i;
		ans=C2(k-1);
	}
	if(a[1]<a[2]&&a[2]<a[3]){
		LL k=3; 
		for(LL i=4;i<=n;i++)
			if(a[i]==a[3])
				k=i;
		ans=k-2;		
	} 
	cout<<ans<<endl;
	return 0;
} 
