#include <bits/stdc++.h>

#define LL long long

using namespace std;

int n,N=1000101,type,l,r;

LL a[1000502];
LL  s[1005002];

inline int lowbit(int x){
	return x&(-x);
}

inline int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

inline void Add(int x,int delta){
	while(x<=N){
		a[x]+=1;
		s[x]+=delta;
		x+=lowbit(x);
	}
}

inline LL Suma(int x){
	LL sum=0;
	while(x>0){
		sum+=a[x];
		x-=lowbit(x);
	}
	return sum;
}

inline LL Sums(int x){
	LL sum=0;
	while(x>0){
		sum+=s[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	while(~scanf("%d",&n)){
		memset(a,0,sizeof a);
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++){
			type=read();
			if(type==0){
				l=read();
				Add(l+1,l);
			} else {
				l=read();r=read();
				l++;r++;
				LL number = Suma(r) - Suma(l-1);
				LL  sum = Sums(r) - Sums(l-1);
				if(number==0) puts("zhizhiwuwu");
				else {
					printf("%lld\n",(LL)(sum/number));
				}
			}
		}
		puts("");
	}
	return 0;
}
