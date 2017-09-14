#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#include<functional>  
#include<cmath>  
#include<cctype>  
#include<cassert>  
#include<climits>  
using namespace std;  
#define For(i,n) for(int i=1;i<=n;i++)  
#define Rep(i,n) for(int i=0;i<n;i++)  
#define Fork(i,k,n) for(int i=k;i<=n;i++)  
#define ForD(i,n) for(int i=n;i;i--)  
#define Forp(x) for(int p=pre[x];p;p=next[p])  
#define RepD(i,n) for(int i=n;i>=0;i--)  
#define MEM(a) memset(a,0,sizeof(a))  
#define MEMI(a) memset(a,127,sizeof(a))  
#define MEMi(a) memset(a,128,sizeof(a))  
#define INF (2139062143)  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define F (1000000009)  
#define MAXM (640000+10)  
#define MAXQ (640000+10)  
#define MAXN (1000000+10)   
typedef long long ll;  
int m,q;  
ll ans[MAXQ];  
struct comm  
{  
   int no,x,y1,y2,v,q,type;  
   comm():no(0),x(0),y1(0),y2(0),v(0),q(0),type(0){}  
   comm(int _no,int _x,int _y1,int _y2,int _v,int _q,int _type):no(_no),x(_x),y1(_y1),y2(_y2),v(_v),q(_q),type(_type){}  
   friend bool operator<(comm a,comm b){return a.x<b.x;}        
}ask[MAXM];  
struct arr_tree  
{  
	ll a[MAXN<<2],sum[MAXN<<2];  
	arr_tree(){memset(a,0,sizeof(a));}  
	void pushup(int o) {
		sum[o]=sum[Lson]|sum[Rson];
	}
	void build(int l,int r,int o) {
		if (l==r) {
			sum[o]=a[l];	return ;
		}
		int m=(l+r)>>1;
		build(l,m,Lson),build(m+1,r,Rson);
		pushup(o);
	}
	void update(int l,int r,int o,int p,ll v) {
		if (l==r) {
			if (v>0)
				sum[o]|=v;
			else sum[o]&=~v;  return;
		}
		int m=(l+r)>>1;
		if (p<=m) update(l,m,Lson,p,v); 
		else update(m+1,r,Rson,p,v);
		pushup(o);
	}
	ll query(int l,int r,int o,int L,int R) {
		if(L<=l && r<=R ) return sum[o];
		int m=(l+r)>>1;
		ll ret=0;
		if(L<=m) ret|=query(l,m,Lson,L,R);
		if(m<R) ret|=query(m+1,r,Rson,L,R); 
		return ret;
	}
   void clear()  
   {  
      memset(a,0,sizeof(a));
	  memset(sum,0,sizeof(a));
   }  
}T;  
comm tmp[MAXM];  
void solve(int l,int r)  
{  
   if (l==r) return;  
   int m=l+r>>1;  
   int s1=l-1,s2=m;  
   Fork(i,l,r) tmp[ask[i].no<=m?++s1:++s2]= ask[i];  
   memcpy(ask+l,tmp+l,sizeof(comm)*(r-l+1));  
   int now=l;  
   Fork(i,m+1,r) //±éÀúÑ¯ÎÊ   
   {  
      if (ask[i].type==2)  
      {  
         while (ask[now].x<=ask[i].x&&now<=m)  
         {  
            if (ask[now].type==1) T.update(1,1000000,1,ask[now].y1,1LL<<(ll)ask[now].v);  
            now++;  
         }  
         ans[ask[i].q]|=T.query(1,1000000,1,ask[i].y1,ask[i].y2);           
      }  
   }  
   now--;  
   while (l<=now) {if (ask[now].type==1) T.update(1,1000000,1,ask[now].y1,-(1LL<<(ll)ask[now].v));now--;}  
   solve(l,m),solve(m+1,r);  
}  
bool work()  
{  
   int type,no=0,x,y,x1,y1,x2,y2,v,q=0;  
   memset(ans,0,sizeof(ans));T.clear();  
   while (scanf("%d",&type))  
   {  
      if (type==0||type==3) break;  
      else if (type==1)  
      {  
         scanf("%d%d%d",&x,&y,&v);  
         no++;ask[no]=comm(no,x,y,0,v,0,1);  
      }  
      else if (type==2)  
      {  
         scanf("%d%d%d",&x2,&y1,&y2);q++;
         no++;ask[no]=comm(no,x2,y1,y2,1,q,2);  
      }  
   }  
   sort(ask+1,ask+1+no);  
   solve(1,no); 
   For(i,q) {
   		int p=0;
   		while(ans[i]) p+=ans[i]&1LL,ans[i]/=2;
   		printf("%d\n",p);
   }
   return type==0;  
}  
int main()  
{  
//   freopen("test.in","r",stdin);  
//   freopen("test.out","w",stdout);  
   int type;  
   scanf("%d",&type);if (type==3) return 0;  
   while (work());  
   return 0;  
}  

