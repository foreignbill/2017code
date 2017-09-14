#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <queue> 
using namespace std;
typedef long long ll;

const int BUFSIZE= 10000000;
char Buf[BUFSIZE+1],*buf=Buf;
template<class T>
void scan(T&a){
for(a=0;*buf<'0'||*buf>'9';buf++);
while(*buf>='0'&&*buf<='9'){a=a*10+(*buf-'0');buf++;}}

class T { 
public: 
    int id;
    ll x;
    T(int b, ll c):id(b), x(c) {
    } 
}; 

inline bool operator > (const T &t1, const T &t2) { 
    return t1.x > t2.x; 
} 

priority_queue<T, vector<T>, greater<T> > q; 
ll a[1000010];
int nxt[1000010];
bool us[1000010];
int n, m, i;
ll sum, an;
T t(0, 0);

int main() {
	freopen("input.txt","r",stdin);
    fread(Buf,1,BUFSIZE,stdin);
    scan(n);
    scan(m);
    sum = 0;
    for (i = 1; i <= n; ++i) {
        scan(a[i]);
        sum += a[i];
    }
    memset(us, 0, sizeof(us));
    for (i = 1; i < n; ++i) {
        nxt[i] = i+1;
        q.push(T(i,a[i] + a[i+1]));
    }
    nxt[n] = 0;
    a[0] = 0;
    int nn = n;
    while (nn > m) {
        t = q.top();
        while (us[t.id] == 1 && !q.empty()) {
            q.pop();
            t = q.top();
        }
        a[t.id] = t.x;
        us[nxt[t.id]] = 1;
        nxt[t.id] = nxt[nxt[t.id]];
        q.pop();
        if (nxt[t.id] != 0)
            q.push(T(t.id, a[t.id] + a[nxt[t.id]]));
        --nn;
    }

    an = 0;
    for (i = 1; i <= n; ++i)
        if (us[i] == 0)
            an += a[i] * a[i];
    an *= m;
    an -= sum * sum;
    printf("%lld\n", an);
    return 0;
}
