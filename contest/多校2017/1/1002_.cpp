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
        printf("Case #%d: %lld\n",++tot,ans);
    }
    return 0;
}
