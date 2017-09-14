#include <bits/stdc++.h>

using namespace std;

const int maxn = 80005;

const int base = 40005;

int n;

bool vis[maxn];
bool num[maxn];
int b[maxn];

int main(){
	//freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		memset(vis,0,sizeof vis);
		memset(num,0,sizeof num);
		int i = 1, tp;
		int ans=0;
		while(i <= n){
			tp = n;
			while(vis[tp-i+base] || vis[tp-i-n+base] || num[tp])
				tp--;
			if(tp==0){
				if(i==0){
					ans=-1;
					break;
				}
				i--;
				vis[b[i]-i+base]=vis[b[i]-i-n+base]=num[b[i]]=0;
				b[i]--;
				while(vis[b[i]-i+base] || vis[b[i]-i-n+base] || num[b[i]])
					b[i]--;
				if(b[i]<=0){
					i--;
					continue;
				}
				continue;
			}
			vis[tp-i+base]=vis[tp-i-n+base]=num[tp]=1;
			b[i]=tp;
			i++;
		}
		if(ans==0)
			for(int i=1;i<=n;i++)
				printf("%d%c",b[i]," \n"[i==n]);
		else puts("-1");
	}
	return 0;
} 
