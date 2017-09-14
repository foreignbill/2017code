#include <cstdio>
#include <cstring>

#define LL long long 

using namespace std;

LL f[2111111];
bool mp[2111111];

int read(){  
    int x=0; char ch=getchar();  
    while (ch<'0' || ch>'9') ch=getchar();  
    while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }  
    return x; 
}

int main(){
	int n,m,B;
	while(n=read(),m=read(),n*m!=0){
		n++;m++;
		memset(mp,0,sizeof(mp));
		B=read();
		for(int cnt=1;cnt<=B;cnt++){
			int x,y,a,b;
			x=read();y=read();a=read();b=read();
			
			for(int i=x+1;i<=x+a-1;i++){
				mp[i*m+y+1]=1;
				mp[i*m+y+b-1]=1;
			}
			for(int j=y+1;j<=y+b-1;j++){
				mp[(x+1)*m+j]=1;
				mp[(x+a-1)*m+j]=1;
			}
		}

		for(int i=1;i<=n;i++) if(!mp[i*m+1]) f[i*m+1]=1;
		for(int i=1;i<=m;i++) if(!mp[m+i]) f[m+i]=1;
		
		for(int i=2;i<=n;i++)
			for(int j=2;j<=m;j++){
				f[i*m+j]=f[(i-1)*m+j]+f[i*m+j-1];
				if(mp[i*m+j]) f[i*m+j]=0;
			}
		printf("%I64d\n",f[n*m+m]);
	}
	
	return 0;
} 
