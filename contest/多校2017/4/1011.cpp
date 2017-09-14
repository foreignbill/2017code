#include <bits/stdc++.h>

using namespace std;

const string s[10]={
".XX.X..XX..X....X..XX..X.XX.",
".......X...X.......X...X....",
".XX....X...X.XX.X...X....XX.",
".XX....X...X.XX....X...X.XX.",
"....X..XX..X.XX....X...X....",
".XX.X...X....XX....X...X.XX.",
".XX.X...X....XX.X..XX..X.XX.",
".XX....X...X.......X...X....",
".XX.X..XX..X.XX.X..XX..X.XX.",
".XX.X..XX..X.XX....X...X.XX."
};

char st[8][30];

int get(int tp){
	for(int i=0;i<=9;i++){
		bool flag = true;
		for(int t=1;t<=7;t++){
			for(int c=0;c<4;c++)
				if(st[t][tp+c]!=s[i][(t-1)*4 + c]){
					flag = false;
				}
		}
		if(flag) return i;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		for(int i=1;i<=7;i++)
			scanf("%s",st[i]);
		int t1 = get(0);
		int t2 = get(5);
		int t3 = get(12);
		int t4 = get(17);
		printf("%d%d:%d%d\n",t1,t2,t3,t4);
	}
	return 0;
} 

