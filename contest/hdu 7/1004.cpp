#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char st[101001]; 

int main(){
	freopen("input.txt","r",stdin);
	while(gets(st)){
		if(st=='\0') break;
		int ans=0;
		int tp=0;
		for(int i=0;i<strlen(st);i++){
			if(tp==0&&'a'<=st[i]&&st[i]<='z'){
				ans++;
				continue;
			}
			if(tp==1&&'A'<=st[i]&&st[i]<='Z'){
				ans++;
				continue;
			} 
			if(tp==0&&'A'<=st[i]&&st[i]<='Z'){
				if('A'<=st[i+1]&&st[i+1]<='Z'){
					tp=1;
					ans+=2;
					continue;
				}
				else ans+=2;
				continue;
			}
			if(tp==1&&'a'<=st[i]&&st[i]<='z'){
				if('a'<=st[i+1]&&st[i+1]<='z'){
					tp=0;
					ans+=2;
					continue;
				}
				else ans+=2;
				continue;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
} 
