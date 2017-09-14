#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <functional>
#include <algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 1000005
#define P 19260817
#define INF 1000000000
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) (((x) >= 0) ? (x) : -(x))
using namespace std;

int a[maxn];
int n,m;
int num[maxn];
bool flag[maxn];
struct node{
    int i,v;
};
int b[maxn][20];
int main() {
//    freopen("input.txt","r",stdin);
    long long i,j,N,n=0,l,r,k,m;
    memset(flag,0,sizeof(flag));
    for(i=2;i<=1000000;i++)if(!flag[i]){
        a[++n]=i;
        for(j=i;j*i<=1000000;j++)flag[i*j]=true;
    }
    while(~scanf("%d%d",&n,&m)){
    	for(int i=1;i<=n;i++)
    		scanf("%d",num+i);
    	
    }
    return 0;
}
