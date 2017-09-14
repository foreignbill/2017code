#include <bits/stdc++.h> 
const int MAXS = 100005;

int numbers[100000];
char buf[MAXS];

void read(char *buf,int len = MAXS){
	int i;
	numbers[i=0]=0;
	for (char *p=buf;*p && p-buf<len;p++)
		if (*p == ' ')
			numbers[++i]=0;
		else
			numbers[i] = numbers[i] * 10 + *p - '0';
} 

int main(){
	freopen("input.txt","rb",stdin);
	int len = fread(buf,1,MAXS,stdin);
	buf[len] = '\0';
	puts(buf);
	return 0;
} 
