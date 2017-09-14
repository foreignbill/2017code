#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P = 1e9+7;
const int N=4;
ll n,m;
struct matrix{
    ll a[N][N];
    int row,col;
    matrix():row(N),col(N){memset(a,0,sizeof(a));}//£¿£¿£¿
    matrix(int x,int y):row(x),col(y){memset(a,0,sizeof(a));}
    ll* operator [] (int x){return a[x];}
    matrix operator * (matrix x){
        matrix tmp ;
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++){
                tmp[i][j]=0;
                for (int k=0;k<N;k++)
                    tmp[i][j]=(tmp[i][j]+a[i][k]*x[k][j])%P;
            }
        return tmp;
    }   
    void operator *= (matrix x){*this = *this * x;}
    matrix operator ^ (ll x){
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

ll pow(ll a,ll n){
	if(n==0) return 1ll;
	ll tmp = pow(a,n/2);
	if(n&1) return tmp*tmp%P*a%P;
	return tmp*tmp%P; 
}

int main(){
	n=3;
	int T;
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		matrix base;
		memset(base.a,0,sizeof base.a);
		base[0][0]=4;base[0][1]=17;base[0][2]=-12;base[0][3]=1;
		base[1][0]=base[2][1]=base[3][3]=1;
		base = base ^ (n-1);
		ll h4,h3,h2;
		h4 = (ll)base[0][0] * 1255LL % P+ base[0][1] * 197LL % P + base[0][2] * 31LL % P - base[0][3] * 16LL % P;
		h3 = (ll)base[1][0] * 1255LL % P+ base[1][1] * 197LL % P + base[1][2] * 31LL % P - base[1][3] * 16LL % P;
		h2 = (ll)base[2][0] * 1255LL % P+ base[2][1] * 197LL % P + base[2][2] * 31LL % P - base[2][3] * 16LL % P; 
		h4 = ((h4 % P) + P)%P;
		h3 = ((h3 % P) + P)%P;
		h2 = ((h2 % P) + P)%P;
		ll res = 3*h4%P*h3%P+9*h4%P*h2%P+9*h3%P*h3%P+27*h3%P*h2%P-18*h4%P-126*h3%P-81*h2%P+192;
		res = (res%P + P) % P;
		res += pow(4ll,n);
		res %= P;
		ll l=1,r=1000000007ll;
		ll ans = -1;
		while(l<=r){
			ll mid = (l+r)/2;
			if(mid*mid <= res){
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		printf("%lld\n",ans); 
	}
	return 0;
}

