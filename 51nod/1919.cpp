#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2000000;
const int MOD = 1e9+7; 
int prime[M / 5], tot = 0, n;
ll f[M + 5]; 
ll p[M + 5];
bool vis[M + 5];

void init(){
    int i, j;
    f[1] = 1;
    for(i=2;i<=M;i++){
        if(!f[i]){
        	f[i] = 1 - i;
            prime[++tot] = i;
        }
        for(j=1;j<=tot && i*prime[j]<=M;j++)
            if(i % prime[j]){
                //phi[i * prime[j]] = phi[i] * (prime[j] - 1);
                //mu[i * prime[j]] = -mu[i];
                //f[i * prime[j]] = f[i] * (1 - prime[j]);
            } else {
                //phi[i * prime[j]] = phi[i] * prime[j];
                //mu[i * prime[j]] = 0;
                if(i!=prime[j]*prime[j])f[i * prime[j]] = f[i] * (1 - prime[j]);
                break;
            }
    }
    for(i=2;i<=M;i++){
        f[i] += f[i-1];
    }
}

ll get_f(int x){
    return (x<=M)?f[x]:p[n/x];
}

void solve(int x){
    if(x<=M) return;
    int i,j=1,t=n/x;
    if(vis[t]) return;
    vis[t]=1;
    p[t] = ((ll)x + 1) * x >> 1;
    while(j < x){
        i = j + 1, j = x / ( x / i), solve(x / i);
        p[t] -= get_f(x / i) * (j - i + 1);
    }
}

int main(){
    init();
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof vis);
        ll ans = 0; 
        if(n <= M)
            ans = f[n]*f[n]%MOD;
        else{
            solve(n);
            ans = p[1]*p[1]%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
} 

