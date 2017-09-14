#include <bits/stdc++.h>

using namespace std;

int f[220000][20],n,k,m;
int mm[220000];
int b[220000];

struct node{
	int id,h;
}info[220000];

bool cmp(node A,node B){
	if(A.id==B.id)
		return A.h<B.h;
	return A.id<B.id;
}

inline void initrmq(int n,int b[]){
 	mm[0] = -1;
	for(int i=1;i<=n;i++){
		mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
		f[i][0]=b[i];
	}
	for(int j=1;j<=mm[n];j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int rmqmin(int x, int y){
    int k=mm[y-x+1];
    return min(f[x][k],f[y-(1<<k)+1][k]);
}
int calc(int id1,int h1,int id2,int h2){
	int hmin=rmqmin(id1,id2);
	if(h1>hmin&&h2>hmin){
		return h1-hmin+h2-hmin+id2-id1;
	}
	return abs(h1-h2)+id2-id1;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	initrmq(n,b);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&info[i].id,&info[i].h);
	sort(info+1,info+1+m,cmp);
	int ans=0;
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++){
			if(calc(info[i].id,info[i].h,info[j].id,info[j].h)<=k)
				ans++;
			if(info[j].id-info[i].id>k)
				break;
		}
	printf("%d\n",ans);
	return 0;
}
