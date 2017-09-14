/*#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll calc1(ll n,ll k){
    if(k==0) return 0;
    if(n==k) return 0;
    return 1;
}
ll calc2(ll n,ll k){
    if(k==0) return 0;
    if(n==k) return 0;
    if(3*k<=n){
        return 2*k;
    }
    if(k>=n/2){
        return n-k;
    }
    ll t=n/3;
    if(n%3==1) return t*2-(k-t)+1;
    if(n%3==2) return t*2-(k-t)+2;
    return t*2-(k-t);
}
int main(){
    ll n,k;
    cin>>n>>k;
    ll Min=calc1(n,k);
    ll Max=calc2(n,k);
    cout<<Min<<" "<<Max<<endl;
    return 0;
}
*/
