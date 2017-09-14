#include <bits/stdc++.h>

#define mp make_pair

using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;

struct node{
	int l,r;
}info[maxn];

multiset<pair<int,int> > S;

bool cmp(node A,node B){
	if(A.l == B.l)
		return A.r<B.r;
	return A.l<B.l; 
} 

int main(){
	int T,n;
	cin>>T;
	while(T--){
		S.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&info[i].l,&info[i].r);
		}
		sort(info+1,info+1+n,cmp);
		for(int i=1;i<=n;i++){
			auto it = S.lower_bound(mp(info[i].l,-1));
			if(it!=S.end()){
				if((it->first) > info[i].l){
					if(it!=S.begin()){
						it--;
						S.insert(mp(info[i].r,it->second));
						S.erase(it);
					} else S.insert(mp(info[i].r,info[i].l));
				} else {
					S.insert(mp(info[i].r,it->second));
					S.erase(it);
				}
			} else if(it!=S.begin()){
				it--;
				S.insert(mp(info[i].r,it->second));
				S.erase(it);
			} else {
				S.insert(mp(info[i].r,info[i].l));
			}
		}
		ll res = 0;
		for(auto it = S.begin();it!=S.end();it++){
			res += (it->first) - (it->second);
		}
		printf("%d %lld\n",S.size(),res);
	}
	return 0;
} 
