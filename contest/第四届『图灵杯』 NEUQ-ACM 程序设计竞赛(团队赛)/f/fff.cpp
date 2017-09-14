#include "stdio.h"
#define ll long long
#define MAXN 1000000007

struct Matrix {
    ll m[100][100];
    int N;
    ll& operator()(int x, int y) {
        return m[x][y];
    }
    void operator*=(Matrix &other) {
        ll mx[100][100] = {0};
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(m[i][j]) {
                    for(int k=0; k<N; k++) {
                        mx[i][k] = (mx[i][k] + m[i][j] * other.m[j][k]) % MAXN;
                    }
                }
            }
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                m[i][j] = mx[i][j];
            }
        }
    }
    void print() {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                printf("%lld ", m[i][j]);
            }
            printf("\n");
        }
    }
};

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    Matrix rst, base;
    rst.N = N;
    base.N = N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%lld", &base(i, j));
            if(i==j) rst(i, j) = 1;
        }
    }
    for(; M; M>>=1) {
        if(M&1) {
            rst *= base;
        }
        base *= base;
    }
    rst.print();
}

