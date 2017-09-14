#include <cstdio>
#include <cstring>

char st[1111];

int main(){
	gets(st);
	int cnt = 0;
	int len = strlen(st);
	for(int i=0;i<len/2;i++)
		if(st[i] != st[len-i-1]) cnt++;
	if(len%2 && !cnt) cnt++;
	puts(cnt!=1?"NO":"YES");
	return 0;
}
