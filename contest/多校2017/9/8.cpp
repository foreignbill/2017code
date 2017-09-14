#include <bits/stdc++.h>

using namespace std;

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}

map<int,int> mp;
map<int,int> mp2;
int b[200005];
bool v[200005];
int a[200005];

int main(){
	int m,x;
	while(~scanf("%d",&m)){
		for(int i=1;i<=m;i++){
			read(b[i]);
		}
		sort(b+1,b+1+m);
		memset(v,0,sizeof v);
		int top = 1;
		a[1] = b[1];
		v[1] = 1;
		for(int i=2;top+(top+1)*top/2<=m;){
			while(v[i]) i++;
			a[++top] = b[i];
			v[i]=1;
			for(int c1=1;c1<=top-1;c1++){
				int num = a[top] + a[c1];
				int l=1,r=m;
				int k=-1;
				while(l<=r){
					int mid = (l+r)/2;
					if(b[mid] > num){
						r = mid - 1;
					} else if(b[mid] > num) {
						l = mid + 1;
					} else if(b[mid] == num && v[mid]==1){
						l = mid + 1;
					} else if(b[mid] == num && v[mid]==0){
						r = mid - 1;
						k = mid;
					}
				}
				while(v[k]) k++;
				v[k]=1;
			}
		}
		for(int i=1;i<=top;i++) printf("%d%c",a[i]," \n"[i==top]);
	}
	return 0;
}
