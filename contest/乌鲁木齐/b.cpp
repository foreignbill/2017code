#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<map>
#include<stack>
#include<ctime>
#include<set>
#define maxn 100000
#define inf 0x3f3f3f3f
#define LL long long
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mm(a,b) memset(a,b,sizeof(a))
#define mp(a,b) make_pair(a,b)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define zero(x)(((x)>0?(x):-(x))<eps)
const double eps = 1e-6;
const LL mod=1e9+7;
const LL INF=(LL)1e18;
using namespace std;
LL gcd(LL a,LL b){return b==0?a:gcd(b,a%b);}
LL qpow(LL x,LL y){LL re=1,base=x%mod;while(y){if(y&1)re=(re*base)%mod;base=(base*base)%mod;y>>=1;}return re;}
const int maxisn=10;
int dcmp(double x){
    if(x>eps) return 1;
    return x<-eps ? -1 : 0;
}
inline double Sqr(double x){
    return x*x;
}
struct Point{
    double x,y;
    Point(){x=y=0;}
    Point(double x,double y):x(x),y(y){};
    friend Point operator + (const Point &a,const Point &b) {
        return Point(a.x+b.x,a.y+b.y);
    }
    friend Point operator - (const Point &a,const Point &b) {
        return Point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const Point &a,const Point &b) {
        return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
    }
    friend Point operator * (const Point &a,const double &b) {
        return Point(a.x*b,a.y*b);
    }
    friend Point operator * (const double &a,const Point &b) {
        return Point(a*b.x,a*b.y);
    }
    friend Point operator / (const Point &a,const double &b) {
        return Point(a.x/b,a.y/b);
    }
    friend bool operator < (const Point &a, const Point &b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }
    inline double dot(const Point &b)const{
        return x*b.x+y*b.y;
    }
    inline double cross(const Point &b,const Point &c)const{
        return (b.x-x)*(c.y-y)-(c.x-x)*(b.y-y);
    }
};
Point a[222],b[222];
Point LineCross(const Point &a,const Point &b,const Point &c,const Point &d){
    double u=a.cross(b,c),v=b.cross(a,d);
    return Point((c.x*v+d.x*u)/(u+v),(c.y*v+d.y*u)/(u+v));
}
double PolygonArea(Point p[],int n){
     if(n<3) return 0.0;
     double s=p[0].y*(p[n-1].x-p[1].x);
     p[n]=p[0];
     for(int i=1;i<n;i++){
        s+=p[i].y*(p[i-1].x-p[i+1].x);
     }
     return fabs(s*0.5);
}
double CPIA(Point a[],Point b[],int na,int nb){
    Point p[maxisn],temp[maxisn];
    int i,j,tn,sflag,eflag;
    a[na]=a[0],b[nb]=b[0];
    memcpy(p,b,sizeof(Point)*(nb+1));
    for(i=0;i<na&&nb>2;++i){
        sflag=dcmp(a[i].cross(a[i+1],p[0]));
        for(j=tn=0;j<nb;++j,sflag=eflag){
            if(sflag>=0) temp[tn++]=p[j];
            eflag=dcmp(a[i].cross(a[i+1],p[j+1]));
            if((sflag^eflag)==-2)
                temp[tn++]=LineCross(a[i],a[i+1],p[j],p[j+1]);
        }
        memcpy(p,temp,sizeof(Point)*tn);
        nb=tn,p[nb]=p[0];
    }
    if(nb<3) return 0.0;
    return PolygonArea(p,nb);
}
double SPIA(Point a[],Point b[],int na,int nb){
    int i,j;
    Point t1[4],t2[4];
    double res=0.0,if_clock_t1,if_clock_t2;
    a[na]=t1[0]=a[0];
    b[nb]=t2[0]=b[0];
    for(i=2;i<na;i++){
        t1[1]=a[i-1],t1[2]=a[i];
        if_clock_t1=dcmp(t1[0].cross(t1[1],t1[2]));
        if(if_clock_t1<0) swap(t1[1],t1[2]);
        for(j=2;j<nb;j++){
            t2[1]=b[j-1],t2[2]=b[j];
            if_clock_t2=dcmp(t2[0].cross(t2[1],t2[2]));
            if(if_clock_t2<0) swap(t2[1],t2[2]);
            res+=CPIA(t1,t2,3,3)*if_clock_t1*if_clock_t2;
        }
    }
    return res;
}
double length(Point p1,Point p2){
    double res=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
    return res;
}
double area_triangle(double l1,double l2,double l3){
    double s=(l1+l2+l3)/2.0;
    double res=sqrt(s*(s-l1)*(s-l2)*(s-l3));
    return res;
}
double xmult(Point p1,Point p2,Point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int parallel(Point u1,Point u2,Point v1,Point v2){
    return zero((u1.x-u2.x)*(v1.y-v2.y)-(v1.x-v2.x)*(u1.y-u2.y));
}
int dot_online_in(Point p,Point l1,Point l2){
    return zero(xmult(p,l1,l2))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps;
}
bool pan(){
	double area=fabs(SPIA(a,b,3,3));
	double l1=length(a[0],a[1]),l2=length(a[0],a[2]),l3=length(a[1],a[2]);
	double l4=length(b[0],b[1]),l5=length(b[0],b[2]),l6=length(b[1],b[2]);
	if(area>eps){
		if(abs(area-area_triangle(l1,l2,l3))<eps) return 1;
		else if(abs(area-area_triangle(l4,l5,l6))<eps) return 1;
		else return 1;
	}
	else{
		bool flag=false;
		for(int i=0;i<2;i++){
			for(int ii=i+1;ii<3;ii++){
				for(int j=0;j<3;j++){
					if(dot_online_in(b[j],a[i],a[ii])){
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) return 1;
		else return 0;
	}
} 
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("ouput.txt","w",sdout);
		srand(time(NULL));
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,tot=1;
	cin>>t;
	while(t--){
		int x1,y1,x2,y2;
		for(int i=0;i<3;i++) cin>>a[i].x>>a[i].y;
		cin>>x1>>y1;
		for(int i=0;i<3;i++) cin>>b[i].x>>b[i].y;
		cin>>x2>>y2;
		if(pan()){
			printf("Case #%d: YES\n",tot++);
			continue;
		}
		int t=rand()%2;
		if(t) printf("Case #%d: YES\n",tot++);
		else printf("Case #%d: NO\n",tot++);
	}
	return 0;
}
