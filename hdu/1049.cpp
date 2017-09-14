#include <cstdio>
main(){int n,u,d,i,c;while(scanf("%d%d%d",&n,&u,&d),n||u||d){i=1,c=0;for(;i<=n;){i+=u;c++;if(i>n)break;i-=d;c++;}printf("%d\n",c);}}
