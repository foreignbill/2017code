#include<bits/stdc++.h>

using namespace std;

const int MAXN=20000000;
bool boo[MAXN];
int prime[3010000];

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

void init(){     
    for(int i=2;i<MAXN;i++){
        if(!boo[i])prime[++prime[0]]=i;
        int t=MAXN/i;
        for(int j=1;j<=prime[0]&&prime[j]<=t;j++){
			boo[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

int main(){
	init();
	int k,cnt=1;
	while(k=read(),k){
		printf("Case %d: %d\n",cnt++,prime[k]);
	}
    return 0;
}

