#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

#define ll long long
#define PQ priority_queue
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define cls(ar,val) memset ( ar, val, sizeof ( ar ) )
#define debug(a) cerr<<#a<<"=="<<a<<endl
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
const int inf = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int maxn=60;
template<typename T> inline void read(T &x){
    x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
int a[maxn][maxn];
vector<int> dd[maxn];
int n,m;
int ans[maxn][maxn];
int main() {
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;while(t--) {
        lpi(i,1,50) dd[i].clear();
        cls(ans,0);
        cls(a,0);
        read(n,m);
        int x,y;
        lpi(i,0,n-1) {
            read(x,y);
            a[x][y]=1;
        }
        lpi(i,0,m-1) {
            read(x,y);
            dd[x].push_back(y);
        }
        lpi(i,1,50) lpi(j,1,50)
        if(a[i][j]) for(auto k:dd[j]) ans[i][k]=1;
        lpi(i,1,50) lpi(j,1,50) if(ans[i][j]) printf("%d %d\n",i,j);
        printf("\n");
    }
    return 0;
}A


#include <bits/stdc++.h>

using namespace std;

int n,b;
int c[10005],d[10005];
int pre[10005];

int main(){
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d",&n,&b);
		for(int i=1;i<=n;i++){
			scanf("%d",c+i);
		}
		for(int i=1;i<n;i++)
			scanf("%d",d+i);
		int res=0;
		bool flag=0;
		for(int i=1;i<n;i++){
			res=res+c[i]-b*d[i];
			if(res<0){
				flag=1;
				break;
			}
		}
		puts(flag?"No":"Yes");
	}
	return 0;
}C

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll p[]={0, 1, 8, 49, 288, 1681, 9800, 57121,
332928, 1940449, 11309768, 65918161, 384199200, 2239277041, 13051463048,
76069501249, 443365544448, 2584123765441, 15061377048200, 87784138523761, 511643454094368, 2982076586042449, 17380816062160328, -1};
int main(){
	int T,tot=1;
	ll n;
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		ll res=-1;
		for(int i=1;p[i]!=-1;i++){
			if(p[i]<n) continue;
			if(p[i]>=n){
				res=p[i];
				break;
			}
		}
		printf("Case #%d: %lld\n",tot++,res);
	}
	return 0;
}E

#include<bits/stdc++.h>
#define MAXN 10050  
#define MAXM 100050
#define INF 10000000  
using namespace std;  
vector<int> G[MAXN];//ÒÑÍÆµ¼µÄ¹«Ê½½¨Á¢µÄÍ¼   
int low[MAXN], dfn[MAXN];  
int dfs_clock;  
int sccno[MAXN], scc_cnt;  
vector<int> scc[MAXN];//´æ´¢SCCµÄµã   
stack<int> S;  
bool Instack[MAXN];  
int n, m;//n¸öÃüÌâ m´ÎÍÆµ¼  
void getMap()  
{  
    int s, t;  
    for(int i = 1; i <= n; i++) G[i].clear();   
    while(m--)  
    {  
        scanf("%d%d", &s, &t);  
        G[s].push_back(t);  
    }   
}  
void tarjan(int u, int fa)  
{  
    int v;  
    low[u] = dfn[u] = ++dfs_clock;  
    S.push(u);  
    Instack[u] = true;  
    for(int i = 0; i < G[u].size(); i++)  
    {  
        v = G[u][i];  
        if(!dfn[v])  
        {  
            tarjan(v, u);  
            low[u] = min(low[u], low[v]);  
        }   
        else if(Instack[v])  
        low[u] = min(low[u], dfn[v]);  
    }  
    if(low[u] == dfn[u])  
    {  
        scc_cnt++;  
        scc[scc_cnt].clear();  
        for(;;)  
        {  
            v = S.top(); S.pop();  
            Instack[v] = false;  
            sccno[v] = scc_cnt;  
            scc[scc_cnt].push_back(v);  
            if(v == u) break;  
        }  
    }   
}  
void find_cut(int l, int r)  
{  
    memset(low, 0, sizeof(low));  
    memset(dfn, 0, sizeof(dfn));  
    memset(sccno, 0, sizeof(sccno));  
    memset(Instack, false, sizeof(Instack));  
    dfs_clock = scc_cnt = 0;  
    for(int i = l; i <= r; i++)  
    if(!dfn[i]) tarjan(i, -1);   
}  
int in[MAXN], out[MAXN];//SCCÈë¶È ³ö¶È   
void suodian()//Ëõµã   
{  
    for(int i = 1; i <= scc_cnt; i++) in[i] = out[i] = 0;   
    for(int i = 1; i <= n; i++)  
    {  
        for(int j = 0; j < G[i].size(); j++)  
        {  
            int u = sccno[i];  
            int v = sccno[G[i][j]];  
            if(u != v)  
            out[u]++, in[v]++;  
        }   
    }    
}  
void solve()  
{  
    if(scc_cnt == 1)  
    {  
        printf("0\n");  
        return ;  
    }  
    int sumin = 0, sumout = 0;//Èë¶ÈÎª0µÄµãÊý ³ö¶ÈÎª0µÄµãÊý  
    for(int i = 1; i <= scc_cnt; i++)  
    {  
        if(in[i] == 0) sumin++;  
        if(out[i] == 0) sumout++;  
    }   
    printf("%d\n", max(sumin, sumout));  
}   
int main()  
{
//	freopen("input.txt","r",stdin);
    int t;  
    scanf("%d", &t);  
    while(t--)  
    {  
        scanf("%d%d", &n, &m);  
        getMap();  
        find_cut(1, n);//ÕÒSCC  
        suodian();   
        solve();   
    }  
    return 0;  
}F

#include <bits/stdc++.h>

using namespace std; 
const int maxn = 100005;
char s[maxn],t[1005];

int S[maxn+5],m;
int pos[maxn+5];
char op[5],to[5];
int delta[15],delta2[15];
unsigned int _Hash[maxn],base[1000],purpose;

inline int lowbit(int x){
	return x&(-x);
}

inline void add(int x,int d,int N){
	while(x<=N){
		S[x]+=d;
		x+=lowbit(x);
	}
}

inline int ask(int r){
	int res=0;
	while(r>0){
		res+=S[r];
		r-=lowbit(r);
	}
	return res;
}

int main(){
	base[0]=1;
	for(int i=1;i<=100;i++)
		base[i]=base[i-1]*207; 
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);getchar();
		gets(s+1);int len1=strlen(s+1);
		gets(t+1);int len2=strlen(t+1);
		memset(S,0,sizeof S);
		for(int i=0;i<=len1;i++){
			pos[i]=0;
			_Hash[i]=_Hash[i-1]*207+s[i];
		}
		purpose=0;
		for(int i=1;i<=len2;i++)
			purpose=purpose*207+t[i];
		for(int i=len2;i<=len1;i++){
			if(_Hash[i]-_Hash[i-len2]*base[len2]==purpose){
				pos[i]=1;
				add(i,1,len1);
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%s",op);
			if(op[0]=='Q'){
				int l,r;
				scanf("%d%d",&l,&r);
				if(l+len2-1>r){
					puts("0");
					continue;
				}
				int res=ask(r)-ask(l+len2-2);
				printf("%d\n",res);
			} else {
				int x;
				scanf("%d %s",&x,to);
				int Min=min(x+len2-1,len1);
				for(int j=x;j<=Min;j++){
                    if(pos[j]==1){
                        add(j,-1,len1);
                        pos[j]=0;
                    }
				}
				s[x]=to[0];
				int left=max(0,x-len2);
				_Hash[left]=0;
				for(int j=left+1;j<=Min;j++)
					_Hash[j]=_Hash[j-1]*207+s[j];
				for(int j=max(x,left+len2);j<=Min;j++)
					if(_Hash[j]-_Hash[j-len2]*base[len2]==purpose){
						add(j,1,len1);
						pos[j]=1;
					}
			}
		}
		puts("");
	}
	return 0;
}G

#include<bits/stdc++.h>
#define maxn 400050
#define LL long long
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf=0x3f3f3f3f;
const int base=200000;
map<string,int>ss;
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int from,int to,int cap,int flow,int cost):from(from),to(to),cap(cap),flow(flow),cost(cost){}
};
struct MCMF{
	int n,m,s,t;
	vector<Edge>edges;
	vector<int>G[maxn];
	int inq[maxn],p[maxn];
	LL d[maxn],a[maxn];
	void init(int n){
		this->n=n;
		for(int i=0;i<n;i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from,int to,int cap,int cost){
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	bool BellmanFord(int s,int t,LL &flow,LL& cost){
		for(int i=0;i<n;i++) d[i]=inf;
		memset(inq,0,sizeof(inq));
		d[s]=0,inq[s]=1,p[s]=0,a[s]=inf;
		queue<int>Q;
		Q.push(s);
		while(!Q.empty()){
			int u=Q.front();  Q.pop();
			inq[u]=0;
			for(int i=0;i<G[u].size();i++){
				Edge& e=edges[G[u][i]];
				if(e.cap>e.flow && d[e.to]>d[u]+e.cost){
					d[e.to]=d[u]+e.cost;
					p[e.to]=G[u][i];
					a[e.to]=min(a[u],(LL)e.cap-e.flow);
					if(!inq[e.to]){
						Q.push(e.to);
						inq[e.to]=1;
					}
				}
			}
		}
		if(d[t]==inf) return false;
		flow+=a[t];
		cost+=d[t]*a[t];
		int u=t;
		while(u!=s){
			edges[p[u]].flow+=a[t];
			edges[p[u]^1].flow-=a[t];
			u=edges[p[u]].from;
		}
		return true;
	}
	void Mincost(int s,int t){
		LL flow=0,cost=0;
		while(BellmanFord(s,t,flow,cost));
		if(flow==2) printf("%lld\n",cost);
		else printf("-1\n");
	}
}mc;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		mc.init(maxn);
		ss.clear();
		int nn=0,mm;
		scanf("%d",&mm);
		while(mm--){
			char s1[100],s2[100];
			int w;
			scanf("%s%s%d",s1,s2,&w);
			if(!ss.count(s1)){
				nn++;
				ss[s1]=nn;
				mc.AddEdge(ss[s1],ss[s1]+base,1,0);
				mc.AddEdge(ss[s1]+base,ss[s1],1,0);
			}
			if(!ss.count(s2)){
				nn++;
				ss[s2]=nn;
				mc.AddEdge(ss[s2],ss[s2]+base,1,0);
				mc.AddEdge(ss[s2]+base,ss[s2],1,0);
			}
			mc.AddEdge(ss[s1]+base,ss[s2],1,w);
			mc.AddEdge(ss[s2]+base,ss[s1],1,w);
		}
		int S=ss["Shanghai"]+base,T=nn+1;
		mc.AddEdge(ss["Xian"]+base,T,1,0);
		mc.AddEdge(ss["Dalian"]+base,T,1,0);
		mc.Mincost(S,T);
	}
	return 0;
}j
