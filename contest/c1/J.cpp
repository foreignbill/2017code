#include<bits/stdc++.h> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,0x3f,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MEMx(a,b) memset(a,b,sizeof(a));
#define INF (0x3f3f3f3f)
#define F (1000000007)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define Pr(kcase,ans) printf("Case #%d: %lld\n",kcase,ans);
#define PRi(a,n) For(i,n-1) cout<<a[i]<<' '; cout<<a[n]<<endl;
#define PRi2D(a,n,m) For(i,n) { \
						For(j,m-1) cout<<a[i][j]<<' ';\
						cout<<a[i][m]<<endl; \
						} 
#pragma comment(linker, "/STACK:102400000,102400000")
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return ((a-b)%F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int getc() {
	char ch=getchar();
	while(!islower(ch)) ch=getchar();return ch-'a';
}
#define MAXN (1000111)
#define MAXL (1010) 
bitset<MAXL> b[26],f[MAXN],g[MAXN];
void addedge(int u,int v,int c) {
	f[v]=(f[u]<<1)&b[c];
	f[v].set(0);
	g[v]=g[u]|f[v];
}
int opr[MAXN][5];
int main()
{
	freopen("test.in","r",stdin);
	freopen("test2.ans","w",stdout);
	int m; 
	while(scanf("%d",&m)==1) {
		cerr<<m<<endl;
		f[0]=1;	
		int len=0,cnt=0;
		Rep(i,26) b[i]=1;
		int n=0;
		while(m--) {
			
			char s[10],c1[10],c2[10];
			scanf("%s",s);
			if (s[0]=='A') {
				opr[++cnt][0]=(s[1]=='S'); //=1 add else query
				opr[cnt][1]=read(),
				opr[cnt][2]=read();
				if (s[1]=='D') opr[cnt][3]=getc();
				else opr[cnt][3]=read();
				opr[cnt][5]=len;
			}
			else if (s[0]=='I') {
				++len;
				int p1=getc(),p2=getc();
				Fork(i,p1,p2) b[i].set(len);
			}	
		}
		For(i,cnt) {
			if (!opr[i][0]) {
				++n;
				addedge(opr[i][1],opr[i][2],opr[i][3]);
			} else {
				int l1=opr[i][1],l2=opr[i][2],t=opr[i][3];
				l1=max(l1,1);
				bool fl=0;
				if (l1<=l2) {
					fl=g[t][l1];
				} 
				puts(fl?"yes":"no");
			}
		}
	}
	return 0;
}

