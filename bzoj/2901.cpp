#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int BUFSIZE= 100000000;
char Buf[BUFSIZE+1],*buf=Buf;
template<class T>
void read(T&a){
for(a=0;*buf<'0'||*buf>'9';buf++);
while(*buf>='0'&&*buf<='9'){a=a*10+(*buf-'0');buf++;}}

int A[2005][2005],B[2005][2005],l1,r1,l2,r2;
int n,m;

int main(){
	freopen("in.txt","r",stdin);
    fread(Buf,1,BUFSIZE,stdin);
	read(n);read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			read(A[i][j]);
			A[i][j]+=A[i-1][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			read(B[i][j]);
			B[i][j]+=B[i][j-1];
		}
	for(int i=1;i<=m;i++){
		read(l1),read(r1),read(l2),read(r2);
		if(l1>l2) swap(l1,l2);
		if(r1>r2) swap(r1,r2);
		ll ret=0;
		for(int i=1;i<=n;i++)
			ret += (ll)(A[l2][i]-A[l1-1][i])*(B[i][r2]-B[i][r1-1]);
		printf("%lld\n",ret);
	}
	return 0;
}
