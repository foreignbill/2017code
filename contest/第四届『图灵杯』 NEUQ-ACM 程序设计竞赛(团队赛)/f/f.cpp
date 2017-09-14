#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll P = 1000000007;
const int N=100;
ll n,m;

ll read(){  
    ll x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

struct matrix{
    ll a[N][N];
    int row,col;
    inline matrix():row(N),col(N){memset(a,0,sizeof(a));}
    inline matrix operator * (matrix x){
        matrix tmp;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++){
                for (int k=0;k<n;k++)
                    tmp.a[i][j]=(tmp.a[i][j]+a[i][k]*x.a[k][j])%P;
            }
        return tmp;
    }
    inline matrix pow(ll x){
        matrix ret;
        for (int i=0;i<=n+1;i++)ret.a[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp=tmp*tmp){if(x&1)ret=ret*tmp;}
        return ret;
    }
};

int num[101];
ll fac[101],k;

int main(){
	n=read();k=read();
	for(int i=0;i<n;i++){
		num[i]=read();
		num[i]%=P;
	}
	matrix tmp;
	for(int i=0;i<n;i++){
		tmp.a[0][i]=read();
		tmp.a[0][i]%=P;
	}
	for(int i=1;i<n;i++)
		tmp.a[i][i-1]=1;
	tmp = tmp.pow(k-n);
	ll ans=0;
	for(int i=0;i<n;i++)
		ans = (ans + tmp.a[0][i] * num[n-i-1] ) % P;
	printf("%lld\n",ans);
	return 0;
}

