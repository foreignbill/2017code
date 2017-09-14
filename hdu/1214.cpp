#include <bits/stdc++.h>
using namespace std;
int fun(int n){return n*(n-1)/2;}
int main(){
    int n;
    while(cin>>n) cout<<fun(n/2)+fun(n-n/2)<<endl;;
    return 0;
}

