#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll P = 1000000007;
const int N=2;
ll n,m;

struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}//£¿£¿£¿
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
    matrix operator - (matrix x){
        matrix tmp ;
        for (int i=0;i<=n+1;i++)
            for (int j=0;j<=n+1;j++){
                tmp[i][j]=a[i][j] - x[i][j] + P;
                tmp[i][j]%=P;
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
};

int main(){
	long long T,nn,mm;
	cin>>T;
	n=0;
	while(T--){
		scanf("%lld%lld",&nn,&mm);
		matrix A,B,ans;
		A[0][0]=1;A[0][1]=2;A[1][0]=1;A[1][1]=0;
		if(nn&1){
			B[0][0]=0;B[0][1]=2;
			B[1][0]=1;B[1][1]=-1;
		} else {
			B[0][0]=1;B[0][1]=0;
			B[1][0]=0;B[1][1]=1;
		}
		ans = ((A ^ nn) - B) ^ (mm-1);
		cout<<(ans[0][0])<<endl;
	}
	return 0;
}
