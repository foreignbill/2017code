#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const double pi = 4.0 * atan(1.0);

int main(){
    int T;
    double a1,b1,a2,b2;
    double s1,s2,x;
    scanf("%d", &T);
    while(T--){
        scanf("%lf%lf%lf%lf",&a1,&b1,&a2,&b2);
        if(a2>=a1) printf("%.3lf\n",pi*a1*b1);
        else if(b1>=b2) printf("%.3lf\n",pi*a2*b2);
        else{
            x = sqrt( ( (a1*a1*b1*b1*a2*a2 - a1*a1*a2*a2*b2*b2)*1.0 / (b1*b1*a2*a2-a1*a1*b2*b2) ) );
            s1 = 0.5*a1*b1*(asin(x/a1)+0.5*sin(2*asin(x/a1)));
            s2 = 0.5*a2*b2*((asin(1.0)+0.5*sin(2*asin(1.0)))-(asin(x/a2)+0.5*sin(2*asin(x/a2))));
            printf("%.3lf\n",4.0*(s1+s2));
        }
    }
    return 0;
}
