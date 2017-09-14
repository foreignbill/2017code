#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;

int a[N];

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}

int main(){
    int T;
	read(T);
    while(T--) {
        int n,m;
		read(n,m);
        for (int i=1;i<=n;i++)
			read(a[i]);
        int k = 1;
        while(k * 4 <= m)
			k *= 4;
        while(m){
	    	while(m>=k){
                for(int i=k+1;i<=n;i++) a[i] ^= a[i-k];
                m-=k;
            }
            k/=4;
        }
        for (int i = 1; i<=n; i++) printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}
