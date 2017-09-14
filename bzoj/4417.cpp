#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int P = 30011;
const int N = 105;
int n,m,maxsize;

struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<maxsize;i++)
            for (int j=0;j<maxsize;j++){
                tmp[i][j]=0;
                for (int k=0;k<maxsize;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }   
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (ll x){
        matrix ret;
        for (int i=0;i<maxsize;i++)ret[i][i]=1;
        matrix tmp = *this;
        for (;x;x>>=1,tmp*=tmp){if(x&1)ret *=tmp;}
        return ret;
    }
    void print(){
        for (int i=0;i<maxsize;i++){
            for (int j=0;j<maxsize;j++)
                printf("%d ",a[i][j]);
            puts("");
        }
    }
};

int main(){
	scanf("%d%d",&n,&m);
	maxsize=n<<1;
	m-=2;
	if(n>m) return 0 * puts("0");
	matrix base;
	for(int i=0;i<n;i++)
		base[i+n][i]=base[i][i+n]=1;
	for(int i=0;i<n;i++)
		for(int j=max(i-1,0);j<=min(i+1,n-1);j++)
			base[i][j]=1;
	base = base ^ (m);
	matrix res;
	res[0][0]=res[1][0]=1;
	if(n==1&&m>=2) res[1][0]=0;
	res = base * res;
	printf("%d\n",res[n-1][0]);
	return 0;
}
