#include <stdio.h>
#include <stdlib.h>

int n;
char s[17];

void dfs(int i){
    if(i==n) printf("%s\n",s);
    else{
        dfs(i+1);
        if(s[i]=='0') s[i]='1';
        else s[i]='0';
        dfs(i+1);
    }
}

int main(){
    int i;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        if(!n) break;
        for(i=0;i<17;i++) s[i]='0';
        s[n]='\0';
        dfs(0);
        printf("\n");
    }
    return 0;
}
