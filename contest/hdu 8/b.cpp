#include <cstdio>
#include <cstring>
#include <iostream> 

using namespace std;

int main(){
	int T;
	cin>>T;
	getchar();
	while(T--){
		char x;
		int N,A,B;
		scanf("%c %d %d %d",&x,&N,&A,&B);
		char x0=x;
		getchar();
		int ans = x=='k';
		for(int i=1;i<=N;i++){
			x0 = (A * (x0 - 'a') + B * i) % 26 + 'a';
			if(x0=='k') ans++;
		}
		printf("%d\n",ans/7);
	} 
	
	return 0;
}
 
