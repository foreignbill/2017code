#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int cnt[26][100005];
int isprezero[26];
int Q[26];
int tmp[100005];
int bit[100005];
char st[100005];
int lth[26];
bool vis[26];

int comp(int a,int b){
	if(lth[a]>lth[b]) return 1;
	if(lth[a]<lth[b]) return -1;
	int i=lth[a];
	while(i>=1){
		if(cnt[a][i] == cnt[b][i]){
			i--;
			continue;
		}
		if(cnt[a][i]>cnt[b][i]) return 1;
		if(cnt[a][i]<cnt[b][i]) return -1;
	}
	return 0;
}

int main(){
	int n,maxlen,tot=0;
	bit[1]=1;
	for(int i=2;i<=100000;i++)
		bit[i] = (ll)bit[i-1]*26ll%MOD;
	while(~scanf("%d",&n)){
		memset(cnt,0,sizeof cnt);
		memset(isprezero,0,sizeof isprezero);
		getchar();
		for(int i=1;i<=n;i++){
			gets(st);
			int len = strlen(st);
			if(len>1){
				isprezero[st[0]-'a']=1;
			}
			for(int j=0;j<len;j++){
				cnt[st[j]-'a'][len-j]++;
				if(len-j>cnt[st[j]-'a'][0])
					lth[st[j]-'a']=len-j;
			}
		}
		for(int i=0;i<26;i++){
			for(int j=1;j<=lth[i];j++){
				cnt[i][j+1] += cnt[i][j] / 26;
				cnt[i][j] %= 26;
			}
			while(cnt[i][lth[i]+1]){
				lth[i]++;
				cnt[i][lth[i]+1] += cnt[i][lth[i]] / 26;
				cnt[i][lth[i]+1] %= 26;
			}
		}
		for(int i=0;i<26;i++)
			for(int j=i+1;j<26;j++)
				if(comp(i,j)<0){
					memcpy(tmp,cnt[i],sizeof tmp);
					memcpy(cnt[i],cnt[j],sizeof cnt[i]);
					memcpy(cnt[j],tmp,sizeof tmp);
					swap(isprezero[i],isprezero[j]);
					swap(lth[i],lth[j]);
				}
		for(int i=0;i<26;i++)
			Q[i]=25-i;
		if(isprezero[25]==1){
			int k=25;
			while(isprezero[k]==1) k--;
			for(int i=25;i>k;i--)
				Q[i]++;
			Q[k]=0;
		}
		ll ans = 0;
		for(int i=0;i<26;i++){
			for(int j=1;j<=lth[i];j++)
				ans = ( ans + Q[i]*cnt[i][j]*bit[j] % MOD ) % MOD;
		}
		printf("Case #%d: %lld\n",++tot,ans);
	}
	return 0;
} 
