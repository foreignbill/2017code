#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+100;
const int MAXX = 1e6+100;
int a[MAX];
int t[MAXX];
bool vis[MAXX];
int n,x,y;
void input(){
	scanf("%d%d%d",&n,&x,&y);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		t[a[i]]++;
	}
}
void work(){
	long long ans =1e18;
	for (int i=2;i<=1e6;i++){
		if (!vis[i]){
			int cnt =0;
			int cnt2 = 0;
			for (int j=i;j<=1e6;j+=i){
				vis[j] = true;
				cnt +=t[j];
				cnt2+=t[j-1];
			}
			ans = min(ans,min(1LL*(n-cnt)*x,1LL*(n-cnt-cnt2)*x+1LL*cnt2*y));
		}
	}
	printf("%I64d\n",ans);
}
int main(){
	input(); 
	work();
	return 0;
}
