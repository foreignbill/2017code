#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
    int m;
    bool operator<(const node &a) const{
        return a.m<m;
    }
};

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	    int i,j,n,sum,m;
	    priority_queue<node>Q;
	    while(!Q.empty()) Q.pop();
	    node p,q;
	    while(~scanf("%d%d",&m,&n)){
	        for(i=0; i<n; i++){
	            scanf("%d",&p.m);
	            Q.push(p);
	        }
	        sum=0;
			for(i=0;i<n-1;i++){
			    p=Q.top(),Q.pop();
			    q=Q.top(),Q.pop();
			    sum+=p.m+q.m;
			    p.m=p.m+q.m;
			    Q.push(p);
			}
	        while(!Q.empty())
	            Q.pop();
	        printf("%d\n",sum);
	    }
	}
    return 0;
}
