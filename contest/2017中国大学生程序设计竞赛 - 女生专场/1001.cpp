#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

bool v[2000];
int ts[2000];

int main(){
	int T,n,m,mins,secs,num;
	string st;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int ans = 0, tot = 0;
		memset(v,0,sizeof(v));
		memset(ts,0,sizeof(ts));
		for(int i=1;i<=m;i++){
			cin>>num;
			scanf("%d:%d",&mins,&secs);
			cin>>st;
			if(v[num]){
				continue;
			}
			if(st=="AC"){
				ts[num] += mins*60 + secs;
				v[num]=1;
			} else {
				ts[num] += 20;
			}
		}
		for(int i=1001;i<=1000+n;i++){
			if(v[i]){
				tot++;
				ans += ts[i];
			}
		}
		cout<<tot<<" "<<ans<<endl;
	}
	return 0;
}
