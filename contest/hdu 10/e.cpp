#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char a[11111],b[11111];
int find(char* a,char* b){
	int i,j;
	int lena=strlen(a),lenb=strlen(b);
	for(i=0;i<lena;i++){
		if(a[i]=='*'){
		    if(i==lena-1)
		            return true;
		    for(j=i;j<lenb;j++)
				if(find(a+i+1,b+j))  return 1;
		}
		else{
		   if(i>=lenb) return 0;
		   if(a[i]=='?')  continue;
		   if(a[i]!=b[i]) return 0;
		}
	}
	return 1;
}
int main(){
	freopen("input.txt","r",stdin); 
	int ans;
	while(gets(a)){
		if(strlen(a)==0) break;
		int k;
		ans=0;
		scanf("%d",&k);
		getchar();
		while(k--){
		   gets(b);
		   if(find(a,b)) ans+=1;
		}
		getchar();
		printf("%d\n",ans);
	}
	return 0;
}
