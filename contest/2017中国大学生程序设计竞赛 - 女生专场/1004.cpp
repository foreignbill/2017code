#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#define LL long long

using namespace std;

const LL MOD = 1e9+7;
const int INF = 1000000;

int mp[111][111];
int g[111][111];
int n;
char ch;
LL a[111];

int main(){
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				cin>>ch;
				mp[i][j] = ch - '0';
				g[i][j] = ch - '0';
				if(mp[i][j] == 0 && i-j){
					mp[i][j] = INF;
				}
			}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if( mp[i][k] + mp[k][j] < mp[i][j] ){
						mp[i][j] = mp[i][k] + mp[k][j];
					}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(g[i][j]==0) continue;
				if(mp[1][i] + g[i][j] == mp[1][j]){
					a[j]++;
				}
			}
		LL ans = 1;
		for(int i=1;i<=n;i++){
			if(a[i]==0) a[i]=1;
			ans = ans * a[i] % MOD;
		}
		cout<<ans % MOD<<endl; 
	}
	return 0;
}
