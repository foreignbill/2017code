#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
const double eps = 1e-6; 
ll ax,bx,cx,ay,by,cy;
inline ll get_dist(ll x1,ll y1,ll x2,ll y2){
    ll dx=x1-x2;
    ll dy=y1-y2;
    return dx*dx+dy*dy;
}

int main(){
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&ax,&ay,&bx,&by,&cx,&cy); 
    if ((by-ay)*(cx-bx)==(cy-by)*(bx-ax)){
        puts("No");
        return 0;
    }
    if (get_dist(ax,ay,bx,by)==get_dist(bx,by,cx,cy)) puts("Yes");
    else puts("No");
    return 0;
}
