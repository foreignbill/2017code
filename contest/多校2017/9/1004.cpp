#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 1000 + 5;

int dcmp(double t){
	if(t > eps) return 1;
	if(t < -eps) return -1;
	return 0;
}

struct Point{
    double x, y;

    Point operator -(const Point & a) const{
        return(Point){(x - a.x),(y - a.y)};
    }

    Point operator +(const Point & a) const{
        return(Point){(x + a.x),(y + a.y)};
    }

    double operator *(const Point & a) const {
        return x * a.y - y * a.x;
    }
};

struct Line{
    Point s, e;
    double k; 

	inline void init(double x,double y){
		s.x = s.y = 0;
		e.x = x; e.y = y;
	}

	inline bool iscross(const Line &P){
		Point x = P.s - s;
		Point y = P.e - s;
		Point t = e - s;
		if(dcmp((t * x) * (t * y)) == 1) return 0; 
		if(dcmp((x * t) * (x * y)) == -1) return 0;
		if(dcmp((y * x) * (y * t)) == -1) return 0;
		return 1;
	}
	
	inline bool overlap(Line P){
		Point x = P.s - s;
		Point y = P.e - s;
		Point t = e - s;
		if(dcmp(t * x) == 0) return 1;
		if(dcmp(t * y) == 0) return 1;
		return 0;
	}

    inline void rev(const Line &L){
    	double a,b,c;
    	a = L.s.y - L.e.y;
    	b = L.e.x - L.s.x;
    	c = L.s.x * L.e.y - L.e.x * L.s.y;//ax + by + c = 0;
    	double tmp = (a * s.x + b * s.y + c) / (a * a + b * b);
		s.x = s.x - 2.0 * a * tmp;
		s.y = s.y - 2.0 * b * tmp;
		tmp = (a * e.x + b * e.y + c) / (a * a + b * b);
		e.x = e.x - 2.0 * a * tmp;
		e.y = e.y - 2.0 * b * tmp;
    }
    
    inline void print(){
    	printf("(%lf,%lf)(%lf,%lf)\n",s.x,s.y,e.x,e.y);	
    }
}l[maxn];
 
int n, i, ans;
Point v;
Line now;
double k, x, y;

int main(){
	freopen("in.txt","r",stdin);
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf",&l[i].s.x,&l[i].s.y,&l[i].k);
			if(i!=1) l[i-1].e = l[i].s;
		}
		l[n].e = l[1].s;
		double x,y;
		scanf("%lf%lf",&x,&y);
		now.init(x,y);
		double nowk = 1.0;
		int ans = 0;
		bool mark = 1;
		int id = 0;
		while(mark){
			//now.print();
			if(nowk < 1e-4) break;
			for(int i=1;i<=n;i++){
				if(i!=id && now.iscross(l[i])){
					ans++;
					nowk *= l[i].k;
					id = i;
					if(now.overlap(l[i])){
						mark = 0;
					}  
					break;
				}
			}
			now.rev(l[id]);
		}
		printf("%d\n",ans);
	} 
    return 0;
}
