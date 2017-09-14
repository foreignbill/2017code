#include <bits/stdc++.h>

using namespace std;

inline bool read(int &num){
    char ch;bool signal_=false;
    ch=getchar();
    if(ch==EOF) return false;
    while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if(ch=='-'){ signal_=true;num=0;}
    else num=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9'){
            num*=10,num+=ch-'0';
    }
    if(signal_) num=-num;
    return true;
}

int n;
int a[2000005];
int b[2000005];

int main(){
	freopen("input.txt","r",stdin); 
	while(read(n)){
		for(int i=1;i<=n;i++)
			read(a[i]),a[i+n]=a[i];
		for(int i=1;i<=n;i++)
			read(b[i]),b[i+n]=b[i];
		int now=a[1]-b[1];
		int nowt=a[1];
		int res=a[1];
		int last=1;
		int k=1;
		for(int i=2;i<=n+n;i++){
			if(now>0){
				now += a[i]-b[i];
				nowt += a[i];
			} else {
				now = a[i]-b[i];
				nowt = a[i];
				last = i;
			}
			if(res<nowt){
				res=nowt;
				k=last;
			}
			if(i-last==n) break;
		}
		printf("%d\n",(k-1+n)%n);
	}
	return 0;
} 
