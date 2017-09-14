#include <bits/stdc++.h>

using namespace std;

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}

int n,m,ans1,ans2;

const int maxn = 400000 + 5; 

int a[maxn];
int toleft[25][maxn];
int T[25][maxn];

void build(int l,int r,int dep){
	if(l == r) return;
	int mid = (l+r)/2;
	int same = mid - l + 1;
	for(int i=l;i<=r;i++)
		if(T[dep][i] < a[mid])
			same--;
	int ls = l, rs = mid + 1;
	for(int i=l;i<=r;i++){
		int flag = 0;
		if((T[dep][i]==a[mid]&&same>0)||(T[dep][i]<a[mid])){
			T[dep+1][ls] = T[dep][i];
			ls++;
			flag = 1;
			if(T[dep][i] == a[mid])
				same--;
		} else {
			T[dep+1][rs] = T[dep][i];
			rs++;
		}
		toleft[dep][i] = toleft[dep][i-1] + flag;
	}
	build(l,mid,dep+1);
	build(mid+1,r,dep+1);
}

int query(int l,int r,int k,int L,int R,int dep){
	if(l == r)
		return T[dep][l];
	int mid = (L+R)/2;
	int x = toleft[dep][l-1] - toleft[dep][L-1];
	int y = toleft[dep][r] - toleft[dep][L-1];
	int ry = r - L - y;
	int cnt = y - x;
	int rx = l - L - x;
	if(cnt >= k)
		return query(L + x, L + y - 1, k, L, mid, dep + 1);
	else
		return query(mid + rx + 1, mid + 1 + ry, k - cnt, mid + 1, R, dep + 1);
}

int main(){
	read(n,m);
	for(int i=1;i<=n;i++){
		read(a[i]);
		T[0][i]=a[i];
	}
	sort(a+1,a+1+n);
	build(1,n,0);
	int l,r,x,k1,k2;
	for(int i=1;i<=m;i++){
		read(l,r,x);read(k1,k2);
		if(k1 > r - l + 1) ans1 = -1;
		else {
			ans1 = query(l,r,k1,1,n,0);
		}
		if(k2>r-l+1) ans2 = -1; 
		else {
			int Left=1,Right=r-l+1;
			int kid;
			while(Left<=Right){
				int mid = (Left+Right)/2;
				int tmp = query(l,r,mid,1,n,0);
				if(tmp>x){
					Right=mid-1;
					kid = mid;
				}
				else Left = mid + 1;
			} 
			int tt = kid + k2 - 1;
			if( kid + k2 - 1 > r - l + 1) ans2 = -1;
			else ans2 = query(l,r,kid + k2 - 1,1,n,0);
		} 
		if(ans1>x) ans1 = -1; 
		if(ans2<x) ans2 = -1;
		printf("%d %d\n",ans1,ans2);
	}
	return 0;
} 
