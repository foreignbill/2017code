#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const ll M = 1e6;
const ll A = 1e5 + 10;
char s[A];
ll fac[] = {...};//表太长 此处省略 详见博客末尾

ll get(ll x){
    if(x >= mod) return 0;
    if(x == 0) return 1;
    ll res = fac[x/M]%mod;
    for(ll i = x/M*M+1 ;i<=x ;i++){
        res = res*i%mod;
    }
    return res;
}

ll fast_pow(ll n,ll m){
    ll res = 1;
    while(m){
        if(m&1) res = res*n%mod;
        n = n*n%mod;
        m >>= 1;
    }
    return res;
}

ll solve(ll x){
    ll a = get(2*x+1),b = get(x+1),c = get(x);
    b = fast_pow(b,mod-2),c = fast_pow(c,mod-2);
    return a*b%mod*c%mod;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        ll n;
        scanf("%I64d%s",&n,s);
        ll len = strlen(s);
        n = n - len;
        if((n&1) || n<0) puts("0");
        else{
            printf("%I64d\n",solve(n/2));
        }
    }
    return 0;
}
