#include <cstdio>
#include <cmath>
#include <cstring>

const int MAXS = 100005;

int map[105];
char buf[MAXS];

int read(int &id){  
    int x=0;
    while (buf[id]<'0' || buf[id]>'9') id++;  
    while (buf[id]>='0' && buf[id]<='9'){ x=x*10+buf[id]-'0'; id++; }  
    return x; 
}

int main(){
	freopen("input.txt","r",stdin);
	int n;
	int i,j,id=0;
	int len=fread(buf,1,MAXS,stdin);
	buf[len] = '\0';
	while(id+2<=len){
		n=read(id);
		int cnt=0;
		int sum=0;
		for(i=0;i<n;i++){
			map[i]=read(id); 
			sum+=map[i];
		}
		int ans=0; 
		if(sum%n){
			puts("silly linlihao159!");
			continue;
		}
		sum=sum/n;
		for(i=0;i<n;i++){
			if(map[i]!=sum){
				map[i+1]-=sum-map[i];
				ans+=abs(sum-map[i]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
