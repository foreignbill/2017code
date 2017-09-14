#include <bits/stdc++.h>

using namespace std;

int n,q,top;
int prime[100005];
bool p[100005];
int a[100005];
int val[100005];
vector<int> f[100005];
vector<int> g[100005];

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}

void init(int n){
	top=0;
	memset(p,0,sizeof p);
	for(int i=2;i<=n;i++){
		if(!p[i]){
			prime[++top]=i;
		}
		for(int j=1;j<=top && i*prime[j]<=n;j++){
			p[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
	for(int i=1;i<=top;i++){
		for(int j=prime[i];j<=n;j+=prime[i]){
			int t=f[j].size();
			for(int k=0;k<t;k++){
				f[j].push_back(f[j][k]*prime[i]);
				g[j].push_back(-g[j][k]);
			}
			f[j].push_back(prime[i]);
			g[j].push_back(1);
		}
	}
}

int main(){
	read(n,q);
	init(n);
	int sum=0,op,x,d;
	for(int i=1;i<=n;i++)
		read(a[i]),sum+=a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<f[i].size();j++){
			val[f[i][j]]+=a[i];
		}
	}
	for(int i=1;i<=q;i++){
		read(op);
		if(op==1){
			read(x,d);
			sum-=a[x];sum+=d;
			for(int i=0;i<f[x].size();i++)
				val[f[x][i]]-=a[x];
			a[x]=d;
			for(int i=0;i<f[x].size();i++)
				val[f[x][i]]+=a[x];
		} else {
			read(x);
			int ans = 0;
			for(int i=0;i<f[x].size();i++)
				ans += val[f[x][i]]*g[x][i];
			printf("%d\n",sum - ans);
		}
	}
	return 0;
} 
