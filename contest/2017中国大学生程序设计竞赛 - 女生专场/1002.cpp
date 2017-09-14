#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 

#define ll long long

using namespace std;

ll f[3005];
ll dist[3005];

struct node{
    ll x,cost;
}info[3005];

bool cmp(node a, node b){
    return a.x<b.x;
}

int main() {
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++)
            cin>>info[i].x>>info[i].cost;
        sort(info,info+n,cmp);
        dist[0]=0;
        info[n].cost=0;
        info[n].x=info[0].x;
        for(int i=1;i<=n;i++)
            dist[i]=dist[i-1]+info[i].x-info[0].x;
        f[0]=info[0].cost;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1]+info[i].cost;
            for(int j=0;j<i;j++){
                ll res=dist[i-1]-dist[j]-(i-j-1)*(info[j].x-info[0].x);
                f[i]=min(f[i], f[j] + res + info[i].cost);
            }
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
