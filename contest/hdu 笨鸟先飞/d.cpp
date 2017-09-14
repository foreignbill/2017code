#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <time.h>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define inf 0x3f3f3f3f
#define mod 1000000007
typedef long long ll;
using namespace std;
const int N=100010;
int n,dp[N],len;
int w[21][21];
int g[3];
int b,c;
int a[10]={1,3,5,7,9};
set<int>p;

bool charge(int x){
    for(int j=2;j<=sqrt(x);j++){
        if(x%j==0)return false;
    }
    return true;
}

void bfs(){
    queue<int>q;
    q.push(2);q.push(3);q.push(5);q.push(7);
    while(!q.empty()){
        int t=q.front(); p.insert(t);
        q.pop();
        for(int i=0;i<5;i++){
            int k=t*10+a[i];
            if(charge(k)&&k<=n){
                q.push(k);
            }
        }
    }
}
 
int main(){
	int T,k;
	cin>>T;
	while(T--){
		p.clear();
	    memset(w,0,sizeof(w));
	    scanf("%d",&k);
	    n=1;
	    for(int i=1;i<=k;i++) n=n*10;
	    bfs();
	    for(set<int>::iterator it=p.begin();it!=p.end();it++){
	        if(*it>(n/10))cout<<*it<<endl;
	    };
	}
    return 0;
}
