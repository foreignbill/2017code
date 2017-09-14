#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double f(int n){
    double s= 1;
    for(int i = 1; i <= n; i++)
        s *= i;
    return s;
}
double c(int m,int n){
    double w=f(m)/(f(n)*f(m-n));
    return w;
}

int main(){
    int t;
    int n,m;
    double x;
    scanf("%d",&t);
    while(t--){
        double p=0;
        scanf("%d%d%lf",&n,&m,&x);
        for(int i=m; i<=n; i++){
            p+=c(n,i)*pow(x,i)*pow(1-x,n-i);
        }
        printf("%.3f\n",p);
    }
    return 0;
}
