#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll P = 1e9+7;
const int N=3;
ll n,m;

struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++){
                tmp[i][j]=0;
                for (int k=0;k<=n;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (ll x){
        matrix ret;
        for (int i=0;i<=n;i++)ret[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp*=tmp){if(x&1)ret *=tmp;}
        return ret;
    }
};

int main(){
	int T;
	cin>>T;
	ll x;
	while(T--){
		n = 2;
		scanf("%lld",&x);
		matrix tmp;
		tmp[0][0]=tmp[0][2]=tmp[1][0]=tmp[2][1]=1;
		tmp = tmp^(x-2);
		ll ans = (tmp[0][0] * 3 + tmp[0][1] * 2 + tmp[0][2]  ) % P;
		printf("%lld\n",ans);
	}
	return 0;
}
