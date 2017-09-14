#include <bits/stdc++.h>

using namespace std;

int n,b;
int c[10005],d[10005];
int pre[10005];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&b);
		for(int i=1;i<=n;i++){
			scanf("%d",c+i);
		}
		for(int i=1;i<n;i++)
			scanf("%d",d+i);
		int res=0;
		bool flag=0;
		for(int i=1;i<n;i++){
			res=res+c[i]-b*d[i];
			if(res<0){
				flag=1;
				break;
			}
		}
		puts(flag?"No":"Yes");
	}
	return 0;
} 
