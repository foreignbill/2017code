#include<cstdio>
#include<cstring>

using namespace std;

int main(){
	freopen("input.txt","r",stdin);
	char ch[11000],ans[11000];
	int now=0,t=0;
	while (gets(ch)) {
		if(strlen(ch)==0) break;
		if (++t!=1) printf("\n");
		int p=0,now=0;
		for (int i=0;i<strlen(ch);i++){
			if (ch[i]=='-'&&p<=0) continue;
			if (ch[i]=='+'&&p>=now) continue;
			if (ch[i]=='-'&&p>0) {p--; continue;}
			if (ch[i]=='+'&&p<now) {p++; continue;}
			
		    for (int ii=now-1;ii>p-1;ii--)
		    ans[ii+1]=ans[ii];
		    
		    ans[p]=ch[i];
		    now++;p++;
		}
		ans[now]='\0';
		printf("Case %d:",t);
		puts(ans);
	}
	return 0;
} 
