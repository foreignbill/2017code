#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=13;
ll n,m,a,b,P;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

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
	int T;
	cin>>T;
	while(T--){
		n=2;
		cin>>a>>b>>P;
		a+=2;b+=2;
		matrix tmp;
		tmp[0][0]=tmp[0][1]=tmp[1][0]=1;
		tmp[1][1]=0;
		tmp = tmp^(gcd(a,b));
		cout<<tmp[1][0]<<endl;
	}
	
	return 0;
}
