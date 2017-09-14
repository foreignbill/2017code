#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int T,ans=0;
    int x,y,R;
    double r,d;
    scanf("%lf%lf",&r,&d);
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&x,&y,&R);
        ll dist = x * x + y * y;
        ll Max = (r-R)*(r-R);
        ll Min = (r-d+R)*(r-d+R);
        if (dist>=Min&&dist<=Max) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
