#include <bits/stdc++.h>

using namespace std;

int n;
int s[2005];

int main(){
    while(~scanf("%d",&n)){
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&s[i]);
            ans^=s[i];
        }
        if(!ans)
        printf("0\n");
        else{
            int tot=0;
            for(int i = 0; i < n;++i){
                int k = ans ^ s[i];
                if( k< s[i])
                	tot++;
            }
            printf("%d\n",tot);
        }
    }
    return 0;
}

