#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

char st1[80005],st2[80005];

int comp(char st1[],char st2[],int len){
	for(int i=0;i<len;i++){
		if(st1[i]==st2[i]) continue;
		if(st1[i]>st2[i]) return 1;
		if(st1[i]<st2[i]) return -1;	
	}
	return 0;
}

int main(){
	int T,id1,id2;
	char mn1,mn2;
	cin>>T;
	getchar();
	while(T--){
		gets(st1);
		gets(st2);
		int len1=strlen(st1);
		int len2=strlen(st2);
		for(int i=0;i<len1;i++) st1[i+len1] = st1[i];
		st1[len1+len1] = '\0';
		
		for(int i=0;i<len2;i++) st2[i+len2] = st2[i];
		st2[len2+len2] = '\0';
		
		mn1=st1[0];
		for(int i=1;i<strlen(st1);i++) if(mn1>st1[i]) mn1=st1[i];
		mn2=st2[0];
		for(int i=1;i<strlen(st2);i++) if(mn2>st2[i]) mn2=st2[i];
		
		int minid1=0,minid2=0;
		
		for(int i=0;i<len1;i++){
			if(minid1==0){
				if(st1[i]==mn1){
					minid1=i;
					continue;
				}
			}
			if(i) if(st1[i]==mn1&&st1[i-1]==mn1) continue; 
			if(st1[i] == mn1){
				if( comp(st1+minid1,st1+i,len1) > 0){
					minid1=i;
				}
			}
		}
		
		for(int i=0;i<len2;i++){
			if(minid2==0){
				if(st2[i]==mn2){
					minid2=i;
					continue;
				}
			}
			if(i) if(st2[i]==mn2&&st2[i-1]==mn2) continue;
			if(st2[i] == mn2){
				if( comp(st2+minid2,st2+i,len1) > 0){
					minid2=i;
				}
			}
		}
		
		int ans=comp(st1+minid1,st2+minid2,len1);
		if(ans==1) puts("bb");
		if(ans==0) puts("ddbb");
		if(ans==-1) puts("dd");
	}
	return 0;
} 
