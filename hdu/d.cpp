#include<iostream>  
#include<algorithm>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
  
int Euler(int n)  
{  
    int ret = n;  
    for(int i = 2; i*i <= n; ++i)  
    {  
        if(n % i == 0)  
        {  
            n /= i;  
            ret = ret - ret/i;  
        }  
        while(n % i == 0)  
            n /= i;  
    }  
    if(n > 1)  
        ret = ret - ret/n;  
    return ret;  
}  
  
int main()  
{  
    int n;  
    while(~scanf("%d",&n) && n)  
    {  
        printf("%d\n",n-Euler(n)-1);  
    }  
  
    return 0;  
}  
