#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
#define mod 998244353
const int MAXN=10000;
int prime[MAXN+10];
void getPrime()//筛法求素数 
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i])prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
long long factor[1000][2];
long long fatCnt=0;
long long getFactors(long long x)//存储一个数的素因子，factor[i][0]表示素因子,factor[i][1]表示该素因子有多少个
{
    fatCnt=0;
    long long tmp=x;
    for(int i=1;prime[i]<=tmp/prime[i];i++)
    {
        factor[fatCnt][1]=0;
        if(tmp%prime[i]==0)
        {
            factor[fatCnt][0]=prime[i];
            while(tmp%(prime[i]*prime[i])==0)
            {
                factor[fatCnt][1]+=2;
                tmp/=(prime[i]*prime[i]);
            }
            while(tmp%prime[i]==0)
            {
            	factor[fatCnt][1]++;
            	tmp/=prime[i];
			}
            fatCnt++;
        }
    }
    if(tmp!=1)
    {
        factor[fatCnt][0]=tmp;
        factor[fatCnt++][1]=1;
    }
    return fatCnt;
}
int main()
{
	getPrime();
    int t;
    scanf("%d",&t);
    while(t--)
	{		
		long long l,r,k;
		scanf("%I64d%I64d%I64d",&l,&r,&k);
		long long ans=1;
		l=l>2?l:2;
		for(long long i=l;i<=r;i++)
		{
			getFactors(i);
			long long res=1;
		    if(fatCnt==0)
		    {
		      ans=(1*k+1);
		      ans%=mod;
		      continue;
			}		      
		    else
		    {
		    	for(long long j=0;j<fatCnt;j++)
                 {
           	       res*=(factor[j][1]*k)%mod+1;
                   res%=mod;
                }
			}		
           ans+=res;
           ans%=mod;          
		}
		printf("%I64d\n",ans);
	}	    
}
