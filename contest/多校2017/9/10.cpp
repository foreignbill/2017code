#include <bits/stdc++.h>

using namespace std;

char s1[2505],s2[2505];
int f[2505][2505];

int main(){
	int T;
	scanf("%d",&T);getchar();
	while(T--){
		gets(s1+1);gets(s2+1);
		int len1 = strlen(s1+1);
		int len2 = strlen(s2+1);
		s1[0]=s2[0]='#';
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int j=1;j<=len2;j++){
			for(int i=0;i<=len1;i++){ 
				if(s2[j]=='*'){
					if(f[i][j-2]==1) f[i][j]=1;
					if(f[i-1][j-1]==1)
						for(int k=0;k+i<=len1;k++){
							if(s1[i+k] == s1[i-1]) f[i+k][j]=1;
							else break;
						}
				} else {
					if(i && f[i-1][j-1] == 1)
						if(s1[i] == s2[j]) f[i][j]=1;
						else if(s2[j] == '.') f[i][j]=1;
				}
			}
		}
		if(f[len1][len2])  puts("yes");
		else puts("no");
	}
	
	return 0;
} 
