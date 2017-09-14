#include<cstdio> 
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 105;
int n,p,k,r,maxsize;
int P;

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
    scanf("%d%d%d%d",&n,&p,&k,&r);
    maxsize=k;
    P=p;
    matrix base;
    for(int i=0;i<k;i++){
        base[i][i]++;
        base[(i-1+k)%k][i]++;
    }
    base = base ^ ((ll)n*k);
    printf("%d\n",base[0][r]);
    return 0;
}
