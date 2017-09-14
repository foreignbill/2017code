#include <bits/stdc++.h>

using namespace std;

int a[105];
bool v[105];
int n,k;

int main(){
	scanf("%d%d",&n,&k);
	memset(v,0,sizeof v);
	for(int i=1;i<=k;i++){
		scanf("%d",a+i);
		n -= a[i] / 8;
		a[i] %= 8;
	}
	if(n>=k){
		puts("YES");
	} else if(n<0){
		puts("NO");	
	} else {
		sort(a+1,a+1+k);
		for(int i=k;i>=1;i--){
			if(v[i]) continue;
			if(a[i] > 6){
				n--;
				v[i]=1;
			}
		}
		for(int i=k;i>=1;i--){
			if(v[i]) continue;
			if(v[i]==5){
				int flg = 0;
				for(int j=1;j<=k;j++){
					if(v[j]) continue;
					if(a[j]<=2){
						v[j]=1;
						flg++;
					}
					if(flg==1) break;
				}
				if(flg){
					n--;
					v[i]=1;
					continue;
				}
			}
		}
		for(int i=k;i>=1;i--){
			if(v[i]) continue;
			if(v[i]==4 || v[i]==3){
				int flg = 0;
				for(int j=1;j<=k;j++){
					if(v[j]) continue;
					if(a[j]<=2){
						v[j]=1;
						flg++;
					}
					if(flg==2) break;
				}
				if(flg){
					n--;
					v[i]=1;
					continue;
				}
			}
		}
		int cnt1 = 0,cnt2 = 0;
		for(int i=1;i<=k;i++){
			if(v[i]) continue;
			if(a[i] == 2) cnt2++;
			if(a[i] == 1) cnt1++;
		}
		int t2 = (cnt2-1)/3+1;
		if(t2>=cnt1) n-= t2;
		else {
			cnt1 -= t2;
			int m = cnt2 % 3;
			if(m==0){
				if((cnt1-1)/4+1>0) n -= (cnt1-1)/4+1;
			}
			if(m==1){
				if((cnt1-4)/4+1>0) n -= (cnt1-4)/4+1;
			}
			if(m==2){
				if((cnt1-5)/4+1>0) n -= (cnt1-5)/4+1;
			}
		}
	}
	if(n<0)
		puts("NO");
	else puts("YES"); 
	return 0;
} 
