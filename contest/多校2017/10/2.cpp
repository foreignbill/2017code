#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9+7;
const int N=5;
ll n,m;

struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++){
                tmp[i][j]=0;
                for (int k=0;k<=n+1;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }   
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (ll x){
        matrix ret;
        for (int i=0;i<=n+1;i++)ret[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp*=tmp){if(x&1)ret *=tmp;}
        return ret;
    }
    void print(){
        for (int i=0;i<=n+1;i++){
            for (int j=0;j<=n+1;j++)
                printf("%d ",a[i][j]);
            puts("");
        }
    }
};


int main(){
	n=3;
	int T;
	ll nn;
	cin>>T;
	while(T--){
		scanf("%lld",&nn);
		matrix base;
		memset(base.a,0,sizeof base.a);
		base[0][0]=4;base[0][1]=17;base[0][2]=-12;base[0][3]=1;
		base[1][0]=base[2][1]=base[3][3]=1;
		if(nn == 2){
			puts("31");
			continue;
		}
		if(nn == 3){
			puts("197");
			continue;
		}
		if(nn == 4){
			puts("1255");
			continue;
		}
		base = base ^ (nn-4);
		ll res = 0;
		res = (ll)base[0][0] * 1255LL % P+ base[0][1] * 197LL % P + base[0][2] * 31LL % P;
		res %= P;
		res += P;
		res %= P;
		printf("%lld\n",res); 
	}
	return 0;
}
