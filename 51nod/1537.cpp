#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9+7;
const int N=2;
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
    void print(){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++)
                printf("%d ",a[i][j]);
            puts("");
        }
    }
};

int main(){
	ll n;
	scanf("%lld",&n);
	matrix base;
	base[0][0]=2;base[0][1]=base[1][0]=1;base[1][1]=0;
	if(n==1){
		puts("2");
	} else if(n==2){
		puts("9");
	} else{
		base = base ^ (n - 2);
		ll a = base[0][0]*3LL % P + base[0][1]*1LL % P;
		a %= P;
		a = a * a % P;
		ll res;
		if(n&1) res = a + 1;
		else res = a;
		printf("%lld\n",res % P);
	}
	
	return 0;
} 
