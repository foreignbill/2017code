/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300005;
ll c[maxn];
int ti[maxn];
struct cmp{
    bool operator()(const int &a,const int &b){
        return c[b]>c[a];
    }
};
priority_queue<int,vector<int>,cmp> Q;
int main() {
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    ll res=0;
    for(int i=1;i<=n;i++){
        scanf("%I64d",&c[i]);
    }
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=k+1;i++) Q.push(i);
    int ans=1,now=k+1;
    while(!Q.empty()){
        int p=Q.top();Q.pop();
        ti[p]=ans+k;
        ans++;
        now++;
        if(now<=n){
            Q.push(now);
        }
    }
    for(int i=1;i<=n;i++){
        res+=(ll)(ti[i]-i)*c[i];
    }
    printf("%I64d\n",res);
    for(int i=1;i<=n;i++) printf("%d%c",ti[i]," \n"[i==n]);
    return 0;
}
*/
