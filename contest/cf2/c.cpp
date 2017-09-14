#include <bits/stdc++.h>

using namespace std;
const int maxn = 1005;
int n;
struct node{
	int x[5];
}info[maxn];
vector<int> ans;

int check(int ii,int j,int k){
	node A,B;
	for(int i=0;i<5;i++){
		A.x[i]=info[j].x[i]-info[ii].x[i];
		B.x[i]=info[k].x[i]-info[ii].x[i];
	}
	int t=0;
	for(int i=0;i<5;i++)
		t += A.x[i]*B.x[i];
	return t;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int t=0;t<5;t++)
			scanf("%d",&info[i].x[t]);
	if(n>300){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		bool ok=1;
		for(int j=1;j<n;j++){
			if(j==i) continue;
			for(int k=j+1;k<=n;k++){
				if(k==i) continue; 
				if(check(i,j,k)>0){
					ok=0;
					break;
				}
			}
		}
		if(ok) ans.push_back(i);
	}
	printf("%d\n",(int)ans.size());
	for(auto t:ans)
		printf("%d\n",t);
	return 0;
} 
