#include <bits/stdc++.h>

using namespace std;

int head[2000],e[20000],nxt[20000],w[20000],dist[2000],x,y,ww,n,m,start,rear,top;

string st;

struct node{int id,dist;};

class cmp{public:bool operator()(int i,int j){return (dist[i] > dist[j]);}};

priority_queue<int,vector<int>,cmp> Q;

int main(){
    while(~scanf("%d%d%d",&n,&start,&rear)){
    	getchar();
    	memset(head,0,sizeof(head));memset(e,0,sizeof(e));memset(nxt,0,sizeof(nxt));
    	memset(w,0,sizeof(w));
    	top=0;
	    for(int i=1;i<=n;i++){
	    	x=i;
			getline(cin,st);
			while(st.find('(')==0){
				y=0;
				int c;
				for(c=1;st[c]!=' ';c++)
					y=y*10 + st[c]-'0';
				ww=0;
				for(c++;st[c]!=')';c++)
					ww=ww*10+st[c]-'0';
				top++;
		        e[top]=y;
		        w[top]=ww;
		        nxt[top]=head[x];
		        head[x]=top;
				if(c+2>st.size()) break;
				st=st.substr(c+2);
	    	}
	    }
	    memset(dist,63,sizeof(dist));
	    dist[start]=0;
	    Q.push(start);
	    while(!Q.empty()){
	        int now=Q.top();
	        Q.pop();
	        for(int k=head[now];k;k=nxt[k]){
				if(w[k]+dist[now]<dist[e[k]]){
				    dist[e[k]]=w[k]+dist[now];
				    Q.push(e[k]);
				}
	        }
	    }
	   	cout<<dist[rear]<<"\n";
	}
    return 0;
}
