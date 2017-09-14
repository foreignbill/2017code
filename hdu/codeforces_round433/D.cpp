#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct node{
    int day,to,cost;
};
vector<node> F;
vector<node> B;
int d,f,t,c,n,m,k;
ll l[1000005];
ll r[1000005];
ll vis[1000005];

bool c1(node A,node B){
    return A.day<B.day;
}

bool c2(node A,node B){
    return A.day>B.day;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d%d",&d,&f,&t,&c);
        if(t==0){
            F.push_back(node{d,f,c});
        } else {
            B.push_back(node{d,t,c});
        }
    }
    sort(F.begin(),F.end(),c1);
    sort(B.begin(),B.end(),c2);
    int cnt=0,left=-1;
    int nowt=-1;
    ll sum=0;
    memset(vis,0,sizeof vis);
    for(int i=0;i<F.size();i++){
        int to=F[i].to;
        while(nowt!=-1&&nowt<F[i].day){
            nowt++;
            l[nowt]=sum;
        }
        if(!vis[to]){
            cnt++;
            sum+=F[i].cost;
            vis[to]=F[i].cost;
        } else {
            if(F[i].cost>=vis[to]) continue;
            sum=sum-vis[to]+F[i].cost;
            vis[to]=F[i].cost;
        }
        if(cnt==n && left==-1){
            left=nowt=F[i].day;
            l[left]=sum;
            continue;
        }
        if(cnt==n && nowt!=-1){
            l[nowt]=sum;
        }
    }
    for(int i=nowt+1;nowt!=-1&&i<=1e6;i++) l[i]=l[i-1];
    sum=0;cnt=0;int right=-1;
    memset(vis,0,sizeof vis);
    nowt=-1;
    for(int i=0;i<B.size();i++){
        int to=B[i].to;
        while(nowt!=-1&&nowt>B[i].day){
            nowt--;
            r[nowt]=sum;
        }
        if(!vis[to]){
            cnt++;
            sum+=B[i].cost;
            vis[to]=B[i].cost;
        } else {
            if(B[i].cost>=vis[to]) continue;
            sum=sum-vis[to]+B[i].cost;
            vis[to]=B[i].cost;
        }
        if(cnt==n && right==-1){
            right=nowt=B[i].day;
            r[right]=sum;
            continue;
        }
        if(cnt==n && nowt!=-1){
            r[nowt]=sum;
        }
    }
    for(int i=nowt-1;nowt!=-1&&i>=1;i--) r[i]=r[i+1];
    ll res=1e15;
    if(left!=-1&&right!=-1)
        for(int i=left;i+k+1<=right;i++)
            res=min(res,l[i]+r[i+k+1]);
    if(res==1e15) puts("-1");
    else printf("%I64d\n",res);
    return 0;
}
