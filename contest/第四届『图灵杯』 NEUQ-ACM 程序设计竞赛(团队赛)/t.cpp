#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000;
char mp[maxn][maxn];

void Draw(int n, int x, int y) {
    if (n == 1) {
        mp[x][y + 1] = mp[x][y + 2] = '_';
        mp[x][y] = mp[x - 1][y + 1] = '/';
        mp[x - 1][y + 2] = mp[x][y + 3] = '\\';
        return;
    }
    int w = 1 << n;
    int h = w >> 1;
    Draw(n - 1, x, y);
    Draw(n - 1, x, y + w);
    Draw(n - 1, x - h, y + w / 2);
}

int main() {
	freopen("output.txt","w",stdout);
	int n;
	bool flag=false;
    while(scanf("%d",&n)){
    	if(n==0) break; 
    	if(flag){
    		puts("");
    	}
    	flag=true;
    	memset(mp,0,sizeof(mp));
	    Draw(n, (1 << n) - 1 , 0);
	    for (int i = 0, st = 1 << n; i < 1 << n; ++i, ++st) {
	        for (int j = 0; j <= st; ++j) {
	            if(mp[i][j])
	            	putchar(mp[i][j]);
	            else
	            	putchar(' ');
	        }
	        puts("");
	    }
	}
    return 0;
}

