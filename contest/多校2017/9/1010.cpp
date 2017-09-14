#include <bits/stdc++.h>

using namespace std;

char s1[2505],s2[2505];
int f[2505][2505];

void make(char s[]){
    int len = strlen(s);
    for(int j=3;j<len;j++){
        if(s[j]=='*'&&s[j-2]=='*'&&s[j-1]==s[j-3]){
            for(int i=j-1;i<len;i++)
                s[i]=s[i+2];
            len-=2;
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);getchar();
    while(T--){
        gets(s1+1);gets(s2+1);
        make(s2+1);
        int len1 = strlen(s1+1);
        int len2 = strlen(s2+1);
        s1[0]=s2[0]='#';
        int i=len1,j=len2;
        bool flag = 0;
		while(i>=0 && j>=0){
			if(i==0 && j==0){
				flag = 1;
				break;
			}
			if(s1[i] == s2[j]){
				i--;j--;
				continue;
			}
			if(s2[j]=='.'){
				i--;j--;
				continue;
			}
			if(s2[j]=='*'){
				if(s2[j-1]!='.'&&s2[j-1]!=s1[i]){
					j-=2;
					continue;
				}
				if(s2[j-1]=='.'){
					int t=i;
					while(s1[i]==s1[t]) i--;
					j-=2;
					continue;
				}
				if(s2[j-1]==s1[i]){
					int t=i;
					while(s1[i]==s1[t]) i--;
					j-=2;
					continue;
				}
			}
			if(s1[i] != s2[j]){
				if(s2[j+2]=='*' && (s1[i+1] == s2[j])){
					int k=0;
					while(s1[i+1+k] == s2[j]){
						k++;
						j--;
					}
					continue;
				}
				break;
			}
		} 
        if(flag)  puts("yes");
        else puts("no"); 
    }
    
    return 0;
} 
