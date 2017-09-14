#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define inf 0x3f3f3f3f
int a[N],t1[N],t2[N],c[N],rk[N],ht[N],r[N],sa[N];
char s[N];
bool cmp(int *r,int a,int b,int l)
{
	return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(char str[],int n,int m)
{
	n++;
	int i, j, p, *x = t1, *y = t2;
	for(i = 0; i < m; i++)c[i] = 0;
	for(i = 0; i < n; i++)c[x[i] = str[i]]++;
	for(i = 1; i < m; i++)c[i] += c[i-1];
	for(i = n-1; i >= 0; i--)sa[--c[x[i]]] = i;
	for(j = 1; j <= n; j <<= 1) {
		p = 0;
		for(i = n-j; i < n; i++)y[p++] = i;
		for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;
		for(i = 0; i < m; i++)c[i] = 0;
		for(i = 0; i < n; i++)c[x[y[i]]]++;
		for(i = 1; i < m; i++)c[i] += c[i-1];
		for(i = n-1; i >= 0; i--)sa[--c[x[y[i]]]] = y[i];
		swap(x,y);
		p = 1;
		x[sa[0]] = 0;
		for(i = 1; i < n; i++)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		if(p >= n)break;
		m = p;
	}
	int k = 0;
	n--;
	for(i = 0; i <= n; i++)rk[sa[i]] = i;
	for(i = 0; i < n; i++) {
		if(k)k--;
		j = sa[rk[i]-1];
		while(str[i+k] == str[j+k])k++;
		ht[rk[i]] = k;
	}
}

int cal(int l,int n)
{
    int i,cnt,ret=0;
    for(i=cnt=1;i<=n;i++)
        if(ht[i]>=l){
            cnt++;
        }
        else{
            if(cnt==k) ret++;
            cnt=1;
        }
    if(cnt==k) ret++;
    return ret;
}

int solve(int l,int n,int k)
{
    int i,cnt,ret=0;
    for(i=cnt=1;i<=n;i++)
        if(ht[i]>=l){
            cnt++;
        }
        else{
            if(cnt==k) ret++;
            cnt=1;
        }
    if(cnt==k) ret++;
    return ret;
}
int main()
{
    int t,ans,i,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&k,s);
        n=strlen(s);
        da(s,n,128);

        ans=0;

        if(k==1){

        }
        else{
            for(i=1;i<=n;i++) ans+=solve(i,n,k);
        }

        printf("%d\n",ans);
    }
}
