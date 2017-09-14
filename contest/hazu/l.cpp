#include<cstdio>
#include<cstring>
using namespace std;

char ch[1000000];

int main(){
	int n;
	scanf("%d",&n);
	int T=0;
	while (n--){
	    T++;
		scanf("%s",ch);
		long long len=0,ans=0,length=strlen(ch);
	    for (long long i=0;i<length-1;i++)
	      if (ch[i]=='A'&&ch[i+1]=='B') ans++;
		printf("Case #%d:\n",T);
		printf("%lld\n",ans);
    }
	return 0; 
}
