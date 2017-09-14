#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<string,int> mp;

char st[11111];

int main(){
	freopen("input.txt","r",stdin);
	mp.clear();
	while(gets(st),strlen(st)>0){
		for(int i=strlen(st)-1;i>=0;i--){
			mp[st]++;
			st[i]='\0';
		}
	}
	while(gets(st)){
		if(strlen(st)<=0) break;
		printf("%d\n",mp[st]);
	}
	return 0;
} 
