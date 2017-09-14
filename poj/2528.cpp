#include<cstdio>
#include<algorithm>
#include<cstring>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 11111
int H[maxn];
int li[maxn],ri[maxn];
int X[maxn*3];
int col[maxn<<4];
int cnt;
using namespace std;
void push_down(int rt)
{
	if(col[rt]!=-1)
	{
		col[rt<<1]=col[rt<<1|1]=col[rt];
		col[rt]=-1;
	}
}
void updata(int L,int R,int c,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		col[rt]=c;
		return;
	}
	push_down(rt);
	int m=(l+r)>>1;
	if(L<=m)
		updata(L,R,c,lson);
	if(R>m)
		updata(L,R,c,rson);
}
void query(int l,int r,int rt)
{
	if(col[rt]!=-1)
	{
		if(!H[col[rt]])
			cnt++;
		H[col[rt]]=1;
		return;
	}
	if(l==r)
		return;
	int m=(l+r)>>1;
	query(lson);
	query(rson);
}
int bin_search(int key,int n)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(X[m]==key)
			return m;
		if(X[m]<key)
			l=m+1;
		else
			r=m-1;
	}
	return -1;
}
int main()
{
	/*freopen("input.txt","r",stdin);*/
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int nn=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&li[i],&ri[i]);
			X[nn++]=li[i];
			X[nn++]=ri[i];
		}
		sort(X,X+nn);
		int m=1;
		for(int i=1;i<nn;i++)
			if(X[i]!=X[i-1])
				X[m++]=X[i];
		for(int i=m-1;i>0;i--)
			if(X[i]!=X[i-1]+1)
				X[m++]=X[i-1]+1;
		sort(X,X+m);
		memset(col,-1,sizeof(col));
		for(int i=0;i<n;i++)
		{
			int l=bin_search(li[i],m);
			int r=bin_search(ri[i],m);
			updata(l,r,i,0,m,1);
		}
		cnt=0;
		memset(H,0,sizeof(H));
		query(0,m,1);
		printf("%d\n",cnt);
	}
	return 0;
}
