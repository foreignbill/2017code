#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll l,r,x,y,k;
    scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k); 
    for(int i=x;i<=y;i++){
        ll tmp = k * i;
        if(l<=tmp&&tmp<=r){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
