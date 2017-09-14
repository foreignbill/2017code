#include <bits/stdc++.h>

using namespace std;

int Bit[32][100005];
int a[100005];
int top[100005];
int BIT0[32],BIT1[32];

int main(){
	int n,p,x,pp;
	while(~scanf("%d%d",&n,&p)){
		int Xor=0;
		memset(top,0,sizeof top);
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			a[i]=x;
			Xor ^= x;
			while(x){
				Bit[top[i]][i]=x%2;
				if(x%2) BIT1[top[i]]++;
				else BIT0[top[i]]++;
				top[i]++;
				x/=2;
			}
		}
		for(int i=1;i<=p;i++){
			scanf("%d",&pp);
			int Or=0,And=0;
			for(int i=0;i<32;i++){
				if(BIT1[i]>Bit[i][pp]) Or += 1<<i;
				if(BIT1[i]==n-1 && Bit[i][pp]==0) And += 1<<i;
				else if(BIT1[i]==n) And += 1<<i;
			}
			printf("%d %d %d\n",And,Or,Xor ^ a[pp]);
		}
	}
	return 0;
} 
