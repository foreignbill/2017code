#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 200005;
const LL mod = 1000000007LL;
LL fac[N],inv[N];
char s[N];
int L[N],R[N];

LL power(LL a,LL k){
    LL ret=1,base=a;
    while(k) {
        if(k & 1) ret = ret * base % mod;
        base = base * base % mod;
        k >>= 1;
    }
    return ret;
}

void init(){
    fac[0]=1;
    for(int i=1;i<N;i++) fac[i] = fac[i-1] * i % mod;
    inv[N-1]=power(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) inv[i] = inv[i+1] * (i + 1) % mod;
}

LL C(int n, int m) {
    if(m<0) return 0;
    if(n<m) return 0;
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}

int main(){
    init();
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) L[i] = (s[i] == '(') ? L[i-1] + 1 : L[i-1];
    for(int i=n;i>=1;i--) R[i] = (s[i] == ')') ? R[i+1] + 1 : R[i+1];
    LL ans = 0;
    for(int i=1;i<=n;i++)
        if(s[i]=='('){
            ans = (ans + C(L[i] - 1 + R[i], R[i] - 1)) % mod;
        }
    cout<<ans<<endl;
    return 0;
}
