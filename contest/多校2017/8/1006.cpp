#include <bits/stdc++.h>

using namespace std;

char s[100005];
int  a[100005][26];

struct node{
	int a[26];
}T[400005];
node ans1,ans2;

void build(int tp,int l,int r){
	if(l==r){
		for(int i=0;i<26;i++)
			T[tp].a[i]=a[l][i];
		return;
	}
	int mid = (l+r)>>1;
	build(tp<<1,l,mid);
	build(tp<<1|1,mid+1,r);
	for(int i=0;i<26;i++)
		T[tp].a[i]=min(T[tp<<1].a[i],T[tp<<1|1].a[i]);
}

node query(int tp,int l,int r,int L,int R){
	if(L<=l && r<=R){
		node ans;
		for(int i=0;i<26;i++)
			ans.a[i]=T[tp].a[i];
		return ans;
	}
	int mid = (l+r)>>1;
	node ans;
	if(R<=mid) return query(tp<<1,l,mid,L,R);
	if(L>mid) return query(tp<<1|1,mid+1,r,L,R);
	ans1 = query(tp<<1,l,mid,L,R);
	ans2 = query(tp<<1|1,mid+1,r,L,R);
	for(int i=0;i<26;i++)
		ans.a[i] = min(ans1.a[i],ans2.a[i]);
	return ans;
}

int main(){
	//freopen("input.txt","r",stdin);
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			scanf("%s",s);
			int len = strlen(s);
			int nowlast = 0;
			for(int j=0;j<len;j++){
				nowlast++;
				if(j==len-1 || (j!=len-1 && s[j+1]!=s[j])){
					if(nowlast > a[i][s[j]-'a'])
						a[i][s[j]-'a'] = nowlast;
					nowlast = 0;
				}
			}
		}
		build(1,1,n);
		int Q,l,r;
		scanf("%d",&Q);
		for(int i=1;i<=Q;i++){
			scanf("%d%d",&l,&r);
			if(l>r) swap(l,r);
			node ans = query(1,1,n,l,r);
			int mx = -1;
			for(int i=0;i<26;i++)
				mx = max(mx,ans.a[i]);
			printf("%d\n",mx); 
		}
	}
	return 0;
} 
