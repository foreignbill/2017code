#include <bits/stdc++.h>

using namespace std; 
const int maxn = 100005;
char s[maxn],t[1005];

int S[maxn+5],m;
int pos[maxn+5];
char op[5],to[5];
int delta[15],delta2[15];
unsigned int _Hash[maxn],base[1000],purpose;

inline int lowbit(int x){
	return x&(-x);
}

inline void add(int x,int d,int N){
	while(x<=N){
		S[x]+=d;
		x+=lowbit(x);
	}
}

inline int ask(int r){
	int res=0;
	while(r>0){
		res+=S[r];
		r-=lowbit(r);
	}
	return res;
}

int main(){
	base[0]=1;
	for(int i=1;i<=100;i++)
		base[i]=base[i-1]*207; 
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&m);getchar();
		gets(s+1);int len1=strlen(s+1);
		gets(t+1);int len2=strlen(t+1);
		memset(S,0,sizeof S);
		for(int i=0;i<=len1;i++){
			pos[i]=0;
			_Hash[i]=_Hash[i-1]*207+s[i];
		}
		purpose=0;
		for(int i=1;i<=len2;i++)
			purpose=purpose*207+t[i];
		for(int i=len2;i<=len1;i++){
			if(_Hash[i]-_Hash[i-len2]*base[len2]==purpose){
				pos[i]=1;
				add(i,1,len1);
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%s",op);
			if(op[0]=='Q'){
				int l,r;
				scanf("%d%d",&l,&r);
				if(l+len2-1>r){
					puts("0");
					continue;
				}
				int res=ask(r)-ask(l+len2-2);
				printf("%d\n",res);
			} else {
				int x;
				scanf("%d %s",&x,to);
				int Min=min(x+len2-1,len1);
				for(int j=x;j<=Min;j++){
                    if(pos[j]==1){
                        add(j,-1,len1);
                        pos[j]=0;
                    }
				}
				s[x]=to[0];
				int left=max(0,x-len2);
				_Hash[left]=0;
				for(int j=left+1;j<=Min;j++)
					_Hash[j]=_Hash[j-1]*207+s[j];
				for(int j=max(x,left+len2);j<=Min;j++)
					if(_Hash[j]-_Hash[j-len2]*base[len2]==purpose){
						add(j,1,len1);
						pos[j]=1;
					}
			}
		}
		puts("");
	}
	return 0;
}
