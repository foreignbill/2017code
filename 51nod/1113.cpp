#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9+7;
const int N=100;
ll n,m;
struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    inline matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++){
                tmp[i][j]=0;
                for (int k=0;k<N;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }
    inline void operator *= (matrix x){*this = *this * x;}
    inline matrix operator ^ (ll x){
        matrix ret;
        for (int i=0;i<N;i++)ret[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp*=tmp){if(x&1)ret *=tmp;}
        return ret;
    }
    void print(int n){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++)
                printf("%d%c",a[i][j]," \n"[j==n-1]);
        }
    }
};

int main(){
	ll n,m;
	scanf("%lld%lld",&n,&m);
	matrix base;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&base[i][j]);
	base = base ^ m;
	base.print(n);
	return 0;
} 
