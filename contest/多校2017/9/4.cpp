#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double eps = 1e-12;
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
    double a, b, c, k;

    inline void fresh(){
        a = s.y - e.y;
        b = e.x - s.x;
        c = e.y * s.x - s.y * e.x;
    }

    inline void rev(const Line & n){
        double tmp = n.a * s.x + n.b * s.y + n.c;
        tmp /= n.a * n.a + n.b * n.b;
        s.x = s.x - 2 * n.a * tmp;
        s.y = s.y - 2 * n.b * tmp;
        tmp = n.a * e.x + n.b * e.y + n.c;
        tmp /= n.a * n.a + n.b * n.b;
        e.x = e.x - 2 * n.a * tmp;
        e.y = e.y - 2 * n.b * tmp;
        fresh();
    }
}l[1010];
 
int n, i, ans;
Point v;
Line now;
double k, x, y;
inline bool pan(int i){
    Point x = l[i].s - now.s;
    Point y = l[i].e - now.s;
    Point v = now.e - now.s;
    double tmp;
    tmp =(v * x) *(v * y);
    if(tmp > eps) return 0;
    tmp =(x * v) *(x * y);
    if(tmp < -eps) return 0;
    tmp =(y * v) *(y * x);
    if(tmp < -eps) return 0;
    return 1;
}

inline bool check(int i){
    Point x = l[i].s - now.s;
    Point y = l[i].e - now.s;
    Point v = now.e - now.s;
    double tmp;
    tmp = v * x;
    if(fabs(tmp) < eps) return 1;
    tmp = v * y;
    if(fabs(tmp) < eps) return 1;
    return 0;
}

int main(){
	freopen("in.txt","r",stdin);
    while(~scanf("%d", &n)){
        for(i = 1; i <= n; ++i){
            scanf("%lf%lf%lf", &l[i].s.x, &l[i].s.y, &l[i].k);
        }
        l[n].e = l[1].s;
        for(i = 1; i < n; ++i) l[i].e = l[i + 1].s;
        for(i = 1; i <= n; ++i) l[i].fresh();
        double tx,ty;
        scanf("%lf%lf", &tx, &ty);
        now.s.x = 0;now.s.y = 0;
        now.e.x = tx;now.e.y = ty;
        now.fresh();
        ans = 0;
        double nowk = 1;
        int id = 0;
        bool mark = 1;
        while(1){
        	printf("(%lf,%lf)(%lf,%lf)\n",now.s.x,now.s.y,now.e.x,now.e.y);	
        	if(nowk<1e-4) break; 
            for(i = 1; i <= n; ++i)
                if(i != id && pan(i)){
                    ans++;
                    nowk *= l[i].k;
                    id = i;
                    if(check(i)) mark = 0;
                    break;
                }
            if(!mark) break;
            now.rev(l[id]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
