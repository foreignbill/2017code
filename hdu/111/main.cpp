#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 65536 * 4 + 7;
int arr[N];

struct segTree{
    #define lc rt<<1
    #define rc rt<<1^1
    #define lson rt<<1, l, m
    #define rson rt<<1^1, m+1, r
    int M, tree[N], lazy[N];

    inline void build(int n){
        M = n - 1; // n = 65536 * 2
        memset(lazy, 0, sizeof(lazy));
        memset(tree, 0, sizeof(tree));
    }

    inline void pushUp(int rt){
        if (tree[lc] != tree[rc]) tree[rt] = -1;
        else tree[rt] = tree[lc];
    }

    inline void pushDown(int rt){
        //if (rt == 65540) printf("pushDown tree[9, 10] = %d\n", tree[rt]);
        if (tree[rt] != -1){ // -1: mixture
            tree[lc] = tree[rc] = tree[rt];
            return;
        }
        if (lazy[rt] == 0) return;
        lazy[lc] = lazy[rc] = 1;
        if (tree[lc] != -1) tree[lc] ^= 1;
        if (tree[rc] != -1) tree[rc] ^= 1;
        lazy[rt] = 0;
    }

    void setval(int L, int R, int val, int rt, int l, int r){
        if (L <= l && r <= R) {
            tree[rt] = val;
            lazy[rt] = 0;
            return;
        }
        pushDown(rt);
        int m = (l + r) >> 1;
        if (L <= m) setval(L, R, val, lson);
        if (m <  R) setval(L, R, val, rson);
        pushUp(rt);
    }

    void invert(int L, int R, int rt, int l, int r){
        if (L <= l && r <= R){
            //printf("invert(%d, %d, rt = %d, %d, %d)\n", L, R, rt, l, r);
            lazy[rt] ^= 1;
            if (tree[rt] != -1) tree[rt] ^= 1;
            //if (rt == 65540) printf("tree[9, 10] = %d\n", tree[rt]);
            return;
        }
        pushDown(rt);
        int m = (l + r) >> 1;
        if (L <= m) invert(L, R, lson);
        if (m <  R) invert(L, R, rson);
        pushUp(rt);
    }

    void query(int rt, int l, int r){
        if (rt > M){ // leaf
            arr[l] = tree[rt];
            if (arr[l]) printf("arr[%d] = 1\n", l);
            return;
        }
        pushDown(rt);
        int m = (l + r) >> 1;
        query(lson);
        query(rson);
        pushUp(rt);
    }
} T;

inline int findR(int l, const int &n){
    for (int i = l; i <= n+1; i++){
        if (!arr[i]) return i - 1;
    }
    return -1;
}

int main(){
    freopen("in.txt", "r", stdin);
    char op, lseg, rseg;
    int l, r, n = 65536 * 2;
    T.build(n);
    for (;~scanf("%c %c%d,%d%c\n", &op, &lseg, &l, &r, &rseg);){
        l++, l <<= 1;
        r++, r <<= 1;
        if (lseg == '(') l++;
        if (rseg == ')') r--;
        printf("--------> %c [%d, %d]\n", op, l, r);
        if (op == 'U'){ // S = S | T
            T.setval(l, r, 1, 1, 1, n);
        } else if (op == 'I'){ // S = S & T
            T.setval(1, l-1, 0, 1, 1, n);
            T.setval(r+1, n, 0, 1, 1, n);
        } else if (op == 'D'){ // S = S - T
            T.setval(l, r, 0, 1, 1, n);
        } else if (op == 'C'){ // S = T - S
            T.setval(1, l-1, 0, 1, 1, n);
            T.setval(r+1, n, 0, 1, 1, n);
            T.invert(l, r, 1, 1, n);
        } else { // op == 'S': S = S^T = (S-T)|(T-S)
            T.invert(l, r, 1, 1, n);
        }
        //T.query(1, 1, n);
    }
    T.query(1, 1, n);
    bool haveans = 0;
    for (int i = 2; i <= n; i++) if (arr[i]){
        haveans = 1;
        l = i;
        r = findR(l, n);
        i = r;
        printf("[%d, %d]:", l, r);
        lseg = (l&1) ? '(' : '[';
        rseg = (r&1) ? ')' : ']';
        if (l == r && l&1) r++;
        l >>= 1, l--;
        r >>= 1, r--;
        printf("%c%d,%d%c", lseg, l, r, rseg);
        putchar(i==n ? '\n' :' ');
    }
    if (!haveans) puts("empty set");
    return 0;
}
