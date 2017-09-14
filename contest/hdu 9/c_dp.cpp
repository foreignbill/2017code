#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int M,N,B;  
int x,y,dx,dy;  
bool X[2000000],Y[2000000];  
long long A[2000000];  
int trans(int x,int y)//二维到一维的映射关系  
{  
    return x*(N+1)+y;  
}  
int main()  
{  
    while(scanf("%d%d",&M,&N) && M*N != 0)  
    {  
        memset(X,0,sizeof(X));  
        memset(Y,0,sizeof(Y));  
        memset(A,0,sizeof(A));  
        scanf("%d",&B);  
        while(B--)  
        {  
            scanf("%d%d%d%d",&x,&y,&dx,&dy);  
            for(int i = x;i < x+dx;++i)  
            {  
                for(int j = y;j < y+dy;++j)  
                {  
                    if(y+dy-1 > j)   Y[trans(i,j)] = 1;    
                    if(x+dx-1 > i)   X[trans(i,j)] = 1;  
                }  
            }  
        }  
        for(int i = 1;i <= N;++i)    A[i] = 1;  
        for(int i = 1;i <= M;++i)    A[i*(N+1)] = 1;//初始化  
        for(int i = 1;i <= M;++i)  
        {  
            for(int j = 1;j <= N;++j)  
            {  
                if(X[trans(i,j)] && Y[trans(i,j)])  continue;  
                A[trans(i,j)] = (Y[trans(i,j)] ? 0 : A[trans(i-1,j)]) + (X[trans(i,j)] ? 0 : A[trans(i,j-1)]);  
            }  
        }  
        printf("%lld\n",A[trans(M,N)]);  
    }  
}  
