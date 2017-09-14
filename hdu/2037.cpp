#include <bits/stdc++.h>

using namespace std;

int n;

struct node{
	int s,t;
}info[111111];

bool comp(node A,node B){
	return A.t<B.t;
}

int main(){
	while(scanf("%d",&n),n){
		for(int i=1;i<=n;i++)
			scanf("%d%d",&info[i].s,&info[i].t);
		sort(info+1,info+1+n,comp);
		int time = 0,cnt = 0;
		for(int i=1;i<=n;i++){
			if(info[i].s>=time){
				cnt++;
				time = info[i].t;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
