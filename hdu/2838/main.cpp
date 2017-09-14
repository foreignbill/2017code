#include <cstdio>
#include <cstring>
#include <iostream>

#define LL long long

using namespace std;

LL index[111111];
LL sum[111111];

int n,x;

int lowbit(int x){
    return x&(-x);
}

void Add(LL a[],int x,int d){
    while(x<=n){
        a[x]+=d;
        x+=lowbit(x);
    }
}

LL getsum(LL a[],int x){
    LL res = 0;
    while(x>0){
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}

int main(){
    while(cin>>n){
        LL ans = 0;
        memset(index,0,sizeof(index));
        memset(sum,0,sizeof(sum));
        scanf("%d",&x);
        Add(index,x,1);
        Add(sum,x,x);
        for(int i=2;i<=n;i++){
            scanf("%d",&x);
            LL INDEX = getsum(index,n) - getsum(index,x-1);
            LL SUM   = getsum(sum,n) - getsum(sum,x-1);
            ans += INDEX * x + SUM;
            Add(index,x,1);
            Add(sum,x,x);
        }
        cout<<ans<<endl;
    }
    return 0;
}
