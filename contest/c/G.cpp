#include <bits/stdc++.h>

using namespace std;
bool g[105][105];
bool vis[105];
int duR[105];
int duC[105];

vector<int> e[105];
double all,ton;

int Q[500];

double topsort(int s,int n){
	Q[1]=1;
	int f=1,r=1;
	int du[105];
	memcpy(du,duR,sizeof du);
	for(int i=2;i<=n;i++)
		if(du[i]==0){
			r++;
			Q[r]=i;
		}
	while(f<=r){
		for(auto ep:e[Q[f]]){
			if(g[Q[f]][ep]==0)continue;
			du[ep]--;
			if(du[ep]==0){
				r++;
				Q[r]=ep;
			}
		}
		f++;
	}
	double x=0,y=0;
	double cnt[105];
	memset(cnt,0,sizeof cnt);
	cnt[1]=1.0;
	for(int i=1;i<=r;i++)
		for(int j=1;j<i;j++){
			if(g[Q[j]][Q[i]]){
				cnt[i]+=cnt[j]/duC[j];
			}
		}
	//for(int i=1;i<=n;i++)
	//	printf("%d ",cnt[i]);
	for(int i=1;i<=r;i++)
		if(duC[Q[i]]==0 && Q[i]!=n) y+=(double)cnt[i];
		else if(duC[Q[i]]==0 && Q[i]==n) x+=(double)cnt[i];
	//printf("%lf %lf\n",x,y);
	if(x+y<0.000001) return 0;
	//cout<<x<<" "<<y<<endl;
	//cout<<x/(x+y)<<endl;
	return x/(x+y);
}

int main(){
	int T,n,m,tot=1;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) e[i].clear();
		memset(duR,0,sizeof duR);
		memset(duC,0,sizeof duC);
		memset(g,0,sizeof g);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			duC[u]++;
			duR[v]++; 
			e[u].push_back(v);
			g[u][v]=1;
		}
		double res = topsort(1,n);
		//cout<<res<<endl;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(g[j][i]==0)continue;
			g[j][i]=0;
			duR[i]--;
			duC[j]--;
			res = max(res,topsort(1,n));
			duR[i]++;
			duC[j]++;
			g[j][i]=1;
		}
		printf("Case #%d: %.6lf\n",tot++,res);
	}
	return 0;
} 
