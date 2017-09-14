#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;

int a[25];
int S[25];
int st[3]={-1,0,1};
int sta[25];
inline bool dfs(int cur,int n,int key,int t){
	if(key==t)	return true;
	if(cur==n){
		return false;
	}else{
		if(t-key>S[cur]||key-t>S[cur]){
			return false;
		}
		for(int i=0;i<3;i++){
			sta[cur]=st[i];
			if(dfs(cur+1,n,key,t+a[cur]*sta[cur])){
				return true;
			}
		}
	}
	return false;
}
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m,cmp);
	S[m-1]=a[m-1];
	for(int i=m-2;i>=0;i--){
		S[i]=S[i+1]+a[i];
	}
	for(int i=0;i<n;i++){
		int key;
		cin>>key;
		if(dfs(0,m,key,0)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
