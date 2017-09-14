#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1111111],n;

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

int pre[1111111];
 
int main(){
    while(~scanf("%d",&n)){
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(a[i]>1000005) continue;
            pre[a[i]]++;
        }
        for(int i=1;i<=1000000;i++)
            pre[i] += pre[i-1];
        int mx=1;
        for(int i=1;i<=1000000;i++)
            mx = max(mx,pre[i]/i+(pre[i]%i?1:0));
        cout<<mx<<endl; 
    }
    return 0;
} 
