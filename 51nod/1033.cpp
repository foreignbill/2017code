#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9+7;
const int N=100;
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

ll n,m;
matrix base;
int dfs(int dep,int pre,int now){
	if(dep> m) return 0;
	if(dep==m){
		base[pre][now]++;
		return 0;
	}
	dfs(dep+1,pre<<1,now<<1|1);
	dfs(dep+1,pre<<1|1,now<<1);
	dfs(dep+2,pre<<2,now<<2);
}

int main(){
	scanf("%lld%lld",&n,&m);
	memset(base.a,0,sizeof base.a);
	dfs(0,0,0);
	base = base ^ (n + 1);
	printf("%lld\n",base[0][(1<<m)-1]);
	return 0;
} 
