#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll P = 200907;
const int N=4;
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

matrix e;

ll x;

int main(){
    e[0][0]=e[0][2]=e[1][0]=e[2][2]=1;
    e[0][1]=2;
    while(cin>>x,x){
        n = 3;
        if(x<=2){
            cout<<x<<endl;
            continue;
        }
        matrix t = e ^ (x-2);
        ll ans = (t[0][0]*2 % P + t[0][1] + t[0][2]) % P;
        cout<<ans<<endl;
    }
    return 0;
}
