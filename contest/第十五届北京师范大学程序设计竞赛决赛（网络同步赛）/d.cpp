#include <cstdio>

int main(){
    int T,n;
    int i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n-1;i++) puts("0");
        printf("%d\n",1<<(n*(n-1)/2));
    }
    return 0;
}
