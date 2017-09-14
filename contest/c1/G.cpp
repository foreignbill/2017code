#include<bits/stdc++.h>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define ForkD(i,k,n) for(int i=n;i>=k;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=Pre[x];p;p=Next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=Next[p])  
#define Lson (o<<1)
#define Rson ((o<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define pb push_back
#define mp make_pair 
#define fi first
#define se second
#define vi vector<int> 
#define pi pair<int,int>
#define SI(a) ((a).size())
#define ALL(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
ll mul(ll a,ll b){return (a*b)%F;}
ll add(ll a,ll b){return (a+b)%F;}
ll sub(ll a,ll b){return (a-b+llabs(a-b)/F*F+F)%F;}
void upd(ll &a,ll b){a=(a%F+b%F)%F;}
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if (ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
ll sqr(ll a){return a*a;}
ld sqr(ld a){return a*a;}
double sqr(double a){return a*a;}

const double eps=1e-8;
int dcmp(double x) {
	if (fabs(x)<eps) return 0; else return x<0 ? -1 : 1; 
}
ld PI = 3.141592653589793238462643383;
class P{
public:
	double x,y;
	P(double x=0,double y=0):x(x),y(y){}
	friend long double dis2(P A,P B){return sqr(A.x-B.x)+sqr(A.y-B.y);	}
	friend long double Dot(P A,P B) {return A.x*B.x+A.y*B.y; }
	friend long double Length(P A) {return sqrt(Dot(A,A)); }
	friend long double Angle(P A,P B) {return acos(Dot(A,B) / Length(A) / Length(B) ); }
	friend P operator- (P A,P B) { return P(A.x-B.x,A.y-B.y); }
	friend P operator+ (P A,P B) { return P(A.x+B.x,A.y+B.y); }
	friend P operator* (P A,double p) { return P(A.x*p,A.y*p); }
	friend P operator/ (P A,double p) { return P(A.x/p,A.y/p); }
	friend bool operator< (const P& a,const P& b) {return dcmp(a.x-b.x)<0 ||(dcmp(a.x-b.x)==0&& dcmp(a.y-b.y)<0 );}
	
}; 
bool operator==(const P& a,const P& b) {
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y) == 0;
} 
typedef P V;

double Cross(V A,V B) {return A.x*B.y - A.y*B.x;}
double Area2(P A,P B,P C) {return Cross(B-A,C-A);}

P GetLineIntersection(P p,V v,P Q,V w){
	V u = p-Q;
	double t = Cross(w,u)/Cross(v,w);
	return p+v*t;
}
P GetLineIntersectionB(P p,V v,P Q,V w){
	return GetLineIntersection(p,v-p,Q,w-Q);
}

bool SegmentProperIntersection(P a1,P a2,P b1,P b2) { 
	double  c1 = Cross(a2-a1,b1-a1) , c2 = Cross(a2-a1,b2-a1),
			c3 = Cross(b2-b1,a1-b1) , c4 = Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(P p,P a1,P a2) {
	return dcmp(Cross(a1-p,a2-p)) == 0 && dcmp(Dot(a1-p,a2-p))<0;
}
P read_point() {
	P a;
	scanf("%lf%lf",&a.x,&a.y);
	return a;	
} 

typedef vector<P> Polygon;
double PolygonArea(Polygon &p) {
	double area=0;
	int n=p.size();
	For(i,n-2) area+=Cross(p[i]-p[0],p[i+1]-p[0]);
	return area/2;
} 
struct Edge{
	int from,to;
	double ang;
	Edge(int _from,int _to,double _ang):from(_from),
		to(_to),ang(_ang){}
};
namespace Kruskal{
	#define MAXN (200000+10) 
	class bingchaji
	{
	public:
		int father[MAXN],n,cnt;
		void mem(int _n)
		{
			n=cnt=_n;
			For(i,n) father[i]=i;
		}
		int getfather(int x) 
		{
			if (father[x]==x) return x;
			
			return father[x]=getfather(father[x]);
		}
		int unite(int x,int y)
		{
			x=getfather(x);
			y=getfather(y);
			if (x!=y) {
				--cnt;
				father[x]=y;
				return 1;
			}
			return 0;
		}
		bool same(int x,int y)
		{
			return getfather(x)==getfather(y);
		}
	}S;
	struct edge{
		int u,v;
		ll w;
		edge(){}
		edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
	};
	bool operator<(edge a,edge b) {
		return a.w<b.w;
	}
	edge road[MAXN];
	int n,m;
	void init(int _n,int _m) {
		n=_n,m=_m;
	}
	void work(){
		S.mem(n);
		sort(road+1,road+1+m);
		ll tot=0,ans=0;
		for(int i=1;i<=m;i++) {
			int p=S.unite(road[i].u,road[i].v);
			if (p)
				ans+=road[i].w,tot++;
		}
		printf("%lld %lld\n",tot,ans);
	}
}
#define MAXN (200000+10)
struct PSLG {
	int n,m,face_cnt;
	ld x[MAXN],y[MAXN];
	vector<Edge> edges;
	vi G[MAXN],pg;
	
	int vis[MAXN*2],left[MAXN*2],prev[MAXN*2];
	vector<Polygon> faces;
	double area[MAXN];
	
	void init(int n) {
		this->n=n;
		Rep(i,n) G[i].clear();
		edges.clear();
		faces.clear();
	}
	double getAngle(int from,int to) {
		return atan2(y[to]-y[from],x[to]-x[from]);
	}
	void AddEdge(int from,int to) {
		edges.pb(Edge(from,to,getAngle(from,to)));
		edges.pb(Edge(to,from,getAngle(to,from)));
		m=SI(edges);
		G[from].pb(m-2);
		G[to].pb(m-1);
	}
	int id[MAXN]; 
	int cmp(int i,int j) {
		return edges[i].ang<edges[j].ang;
	}

	void Build() {
		Rep(u,n) {
			int d=SI(G[u]);
			
			vector<pair<double,int> > p;
			Rep(i,d) p.pb(mp(edges[G[u][i]].ang,i));
			sort(ALL(p));
			pg.clear();
			pg.insert(pg.end(),G[u].begin(),G[u].end());
			Rep(i,d) G[u][i]=pg[p[i].se];
			
//			Rep(i,d) {
//				Fork(j,i+1,d-1) {
//					if (edges[G[u][i]].ang>edges[G[u][j]].ang) {
//						swap(G[u][i],G[u][j]);
//					}
//				}
//			}
			Rep(i,d) {
				prev[G[u][(i+1)%d]]=G[u][i];
			}
		}
		MEM(vis)
		face_cnt=0;
		Rep(u,n) {
			Rep(i,SI(G[u])) {
				int e=G[u][i];
				if (!vis[e]) {
					face_cnt++;
					Polygon poly;
					while(1) {
						vis[e]=1;
						left[e]=face_cnt; 
						int from = edges[e].from;
						P p(x[from],y[from]);
						poly.pb(p);
						e=prev[e^1];
						if (e==G[u][i]) break;
					}
					faces.pb(poly);
				}
			} 
		}
		Rep(i,face_cnt) {
			area[i]=PolygonArea(faces[i]);
		}
	}
}g;
int isPointInPolygon(P p,Polygon poly) {
    int wn=0;
    int n=poly.size();
    Rep(i,n) {
        if (OnSegment(p,poly[i],poly[(i+1)%n])) return -1;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1 = dcmp(poly[i].y-p.y);
        int d2 = dcmp(poly[(i+1)%n].y-p.y);
        if ( k > 0 && d1 <= 0 && d2 > 0 ) wn++;
        if ( k < 0 && d2 <= 0 && d1 > 0 ) wn--;
    }
    if (wn!=0) return 1;
    return 0;
}

int n, sz;
int w[MAXN*2];
void work() {
	int m=read();
	g.init(sz);
	Rep(i,sz) g.x[i]=read(),g.y[i]=read();
	Rep(i,m) {
		int u=read()-1,v=read()-1;
		g.AddEdge(u,v);
		w[i]=read();
	}
	g.Build();
	int cnt=0;
	for(int i=0,e=0;i<m;i++,e+=2)
	{
		int u=g.left[e],v=g.left[e^1];
		if (u!=v) {
			Kruskal::road[++cnt]=Kruskal::edge(u,v,w[i]);	
		} 
	}
	Kruskal::init(g.face_cnt,cnt);
	Kruskal::work();
}
int main()
{
	freopen("test.in","r",stdin);
	freopen("test2.ans","w",stdout);
	while(scanf("%d",&sz)==1) {
//		cout<<sz<<endl;
		work();
	}
	return 0;
}

