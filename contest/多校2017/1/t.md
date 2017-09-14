# 1001 Add More Zero
There is a youngster known for amateur propositions concerning several mathematical hard problems.
Nowadays, he is preparing a thought-provoking problem on a specific type of supercomputer which has ability to support calculations of integers between 0 and $latex 2^{m}-1 $ (inclusive).
As a young man born with ten fingers, he loves the powers of 10 so much, which results in his eccentricity that he always ranges integers he would like to use from 1 to $latex 10^k$ (inclusive).
For the sake of processing, all integers he would use possibly in this interesting problem ought to be as computable as this supercomputer could.
Given the positive integer m, your task is to determine maximum possible integer k that is suitable for the specific supercomputer.

找比$latex 2^m-1$ 小的中最大的$latex 10^k$
事实上，k=mlog2。

```
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int m;
	int tot=0;
	while(~scanf("%d",&m)){
		int ans = (int)(m*log(2)/log(10));
		printf("Case #%d: %d\n",++tot,ans);
	}
	return 0;
} 
```

# 1002 Balala Power!
Talented Mr.Tang has n strings consisting of only lower case characters. He wants to charge them with Balala Power (he could change each character ranged from a to z into each number ranged from 0 to 25, but each two different characters should not be changed into the same number) so that he could calculate the sum of these strings as integers in base 26 hilariously.

Mr.Tang wants you to maximize the summation. Notice that no string in this problem could have leading zeros except for string 0. It is guaranteed that at least one character does not appear at the beginning of any string.

The summation may be quite large, so you should output it in modulo 1e9+7.

首先这个问题原型叫做最大映射问题。
[blog](http://blog.csdn.net/yang20141109/article/details/51284495)
是将所有字母对应位置的位权加起来排序赋值的。
这里注意到最多可能到10W位，也就是说会爆ll，这种情况下是不能直接算出值来比较的。
事实上，将某个字母对应位的值统计下来后可以将整个数组看作是一个大数，在进行过进位运算之后，进行类似字符串的排序，然后贪心分配权。
如果存在前导字母作为0的话，需要向前找到第一个非前导字母，将之间的前导字母都前移一位。

```
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
struct node{
    int t[100005];
};

char st[100005];
int k[30];
int len,n;
node a[26];
bool vis[30];
int maxlen;

bool cmp(int x,int y){
    if(a[x].t[0]>a[y].t[0])
    	return 1;
    if(a[x].t[0]<a[y].t[0])
    	return 0;
    for (int i=a[x].t[0];i;i--)
        if (a[x].t[i]>a[y].t[i])
        	return 1;
        else if(a[x].t[i]<a[y].t[i])
    		return 0;
    return 0;
}


int main(){
    int tot=0;
    while(~scanf("%d",&n)){
        memset(vis,0,sizeof vis);
        for(int i=0;i<26;i++)
            memset(a[i].t,0,sizeof(a[i].t));
        for(int p=1;p<=n;p++){
            scanf("%s",st);
            len = strlen(st);
            vis[st[0]-'a'] = 1;
            for(int i=0;i<len;i++){
                a[st[i]-'a'].t[len-i]++;
                a[st[i]-'a'].t[0]=max(a[st[i]-'a'].t[0],len-i);
            }
        }
        maxlen = 0;
        for(int i=0;i<=25;i++){
            k[i]=i;
            for(int j=1;j<=a[i].t[0];j++){
                a[i].t[j+1]+=a[i].t[j] / 26;
                a[i].t[j] %= 26;
            }
            while(a[i].t[a[i].t[0] + 1]>0){
                ++a[i].t[0];
                a[i].t[a[i].t[0] + 1] = a[i].t[a[i].t[0]] / 26;
                a[i].t[a[i].t[0]] %= 26;
            }
            maxlen=max(maxlen,a[i].t[0]);
        }
        sort(k,k+26,cmp);
        ll ans=0,tmp=1;
        int now = 25;
        while(vis[k[now]]&&now>0)
            now--;
        for(int i=now;i<=25;i++)
            k[i] = k[i+1];
        for(int i=1;i<=maxlen;i++){
            for(int j=0;j<25;j++){
                ans += (ll)(25 - j) * tmp * a[k[j]].t[i] % MOD;
                ans %= MOD;
            }
            tmp = tmp * 26 % MOD;
        }
        printf("Case #%d: %lldn",++tot,ans);
    }
    return 0;
}
```

# 1006 Function
[hdu6038](http://acm.hdu.edu.cn/showproblem.php?pid=6038)

问有多少种取值方法使得$latex f(i)=b_{f(a_i)}$中，$latex f(i)$全部合法。

样例可以写为：
$latex f(0)=b_{f(2)}$
$latex f(1)=b_{f(0)}$
$latex f(2)=b_{f(1)}$

假设有f(0)就可以解出f(1)然后又解出f(2)而由f(2)又推回到f(0)

如果a中有长度为n的循环节，b中有长度为m的循环节，那么当
$latex nmod m == 0$时，b中的长度为m的循环节就可以作为a这个循环的值,并且有m中对应方法。对于a中每一个环，枚举b中每一个环，如果有满足$latex nmod m==0$，采用加法原理，然后a的每一个环采用乘法原理。

```
#include<bits/stdc++.h>
using namespace std;


const int N=1000010;
const int mod=1e9+7;
int n,m,cnt;
int a[N],b[N],c[N],vis[N];
void dfsa(int u) {
    if(vis[u])return;
    vis[u]=1;
    ++cnt;
    if(!vis[a[u]])dfsa(a[u]);
}
void dfsb(int u) {
    if(vis[u])return;
    vis[u]=1;
    ++cnt;
    if(!vis[b[u]])dfsb(b[u]);
}
int read() {
    int f=1,x=0;
    char ch;
    do {
        ch=getchar();
        if(ch=='-')f=-1;
    } while(ch<'0'||ch>'9');
    do {
        x=x*10+ch-'0';
        ch=getchar();
    } while(ch>='0'&&ch<='9');
    return f*x;
}
int main() {
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF) {
        memset(vis,0,sizeof(vis)); 
        memset(c,0,sizeof(c));
        for(int i=0; i<n; i++)
            a[i]=read();
        for(int i=0; i<m; i++)
            b[i]=read();
        for(int i=0; i<m; i++)
            if(!vis[i]) {
                cnt=0;
                dfsb(i);
                c[cnt]++;
            }
        for(int i=1; i<=m; i++)
            c[i]=1LL*i*c[i]%mod;
        int lim=max(n,m);
        for(int i=lim; i; i--)
            for(int j=i+i; j<=lim; j+=i)
                c[j]=(c[j]+c[i])%mod;
        for(int i=0; i<=n; i++)
            vis[i]=0;
        int ans=1;
        for(int i=0; i<n; i++)
            if(!vis[i]) {
                cnt=0;
                dfsa(i);
                ans=1LL*ans*c[cnt]%mod;
            }
        printf("Case #%d: %dn",++cas,ans);
    }
}
```

# 1011 KazaQ's Socks
[hdu](http://acm.hdu.edu.cn/showproblem.php?pid=6043)

前n天为$latex 1,2,3,...,n$
之后便是$latex 1,2,3,...,n-1,1,2,3,...,n$的循环。

```
#include <cstdio>

int main(){
	int tot=0;
	long long n,k;
	while(~scanf("%lld%lld",&n,&k)){
		long long ans;
		if(k<=n){
			ans = k;
		} else {
			k-=n;
			long long t = (k-1) / (n-1);
			if(t%2==0){
				ans = (k-1) % (n-1) + 1;
			} else {
				ans = (k-1) % (n-1) + 1;
				if(ans==(n-1))
					ans = n;
			}
		}
		printf("Case #%d: %dn",++tot,ans);
	}
	return 0;
} 
```