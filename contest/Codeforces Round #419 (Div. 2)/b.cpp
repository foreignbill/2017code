#include <bits/stdc++.h>

using namespace std;

const int maxn = 200000;

int presum[200005],n,k,q,l,r;

int A[maxn*4];

int lowbit(int x){
	return x&(-x); 
}

void add(int id){
	while(id<=maxn){
		A[id]++;
		id+=lowbit(id);
	}
}

int ask(int id){
	int sum=0;
	while(id){
		sum+=A[id];
		id-=lowbit(id); 
	}
	return sum;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout); 
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l,&r);
		presum[l]++;
		presum[r+1]--;
	}
	for(int i=1;i<=maxn;i++)
		presum[i]+=presum[i-1];
	for(int i=1;i<=maxn;i++)
		if(presum[i]>=k)
			add(i);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&l,&r);
		int sum = ask(r) - ask(l-1);
		printf("%d\n",sum);
	}
	return 0;
}
