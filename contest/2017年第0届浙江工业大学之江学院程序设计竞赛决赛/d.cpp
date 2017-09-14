#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int P = 100000000;
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
    ll x, y, t, ans;
    n=1;
    matrix a; 
    while(~scanf("%lld%lld%lld",&x,&y,&t)){
    	ll tmp = (x+y)%P;
    	a[0][0]=3;a[0][1]=1;
    	a[1][0]=0;a[1][1]=1;
    	a = a ^ t;
		ans = ((tmp*a[0][0]%P+P) - (a[0][1]*tmp) % P)%P+P;
		ans %= P;
		printf("%lld\n",ans);
	}
    return 0;
}
