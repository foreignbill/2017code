#include <bits/stdc++.h>

using namespace std;

int a[111111],b[111111],dp1[1111111],dp2[1111111];

int main(){
    int n,m,T;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",a+i);
            dp1[a[i]] = max(dp1[a[i]],dp1[a[i]-1]+1);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",b+i);
            dp2[b[i]] = max(dp2[b[i]],dp2[b[i]-1]+1);
        }
        int ans = -INT_MAX;
        for(int i=1;i<=1111110;i++)
            if(dp1[i]==dp2[i]&&ans<dp1[i]) ans = dp1[i];
        cout<<ans<<endl;
    }
    return 0;
}

