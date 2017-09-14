#include <bits/stdc++.h>

using namespace std;

const int maxn = 60005;

int cb[maxn]; 
int ce[maxn];
int s[maxn];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		memset(cb,0,sizeof cb);
		memset(ce,0,sizeof ce);
		memset(s,0,sizeof s);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(cb[x]==0) cb[x] = i;
			ce[x]=i;
		}
		for(int i=1;i<=n;i++)
			if(c[i]) s[c[i]]++;
		for(int i=1;i<=60000;i++) s[i]+=s[i-1];
		
	}
	return 0;
} 
