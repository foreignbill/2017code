#include <bits/stdc++.h>

using namespace std;

int main(){
	int x1,y1,x2,y2;
	int dx,dy;
	cin>>x1>>y1>>x2>>y2;
	cin>>dx>>dy;
	int DX = (x2-x1);
	int DY = (y2-y1);
	if(dx==0 && dy==0){
		puts("YES");
		return 0; 
	}
	if(dx==0){
		if(DY % dy==0){
			puts("YES");
			return 0;
		} else {
			puts("NO");
			return 0;
		}
	}
	if(dy==0){
		if(DX % dx==0){
			puts("YES");
			return 0;
		} else {
			puts("NO");
			return 0;
		}
	}
	int t = (DX % dx)||(DY % dy);
	if(t){
		puts("NO");
		return 0;
	}
	int d1 = DX / dx;
	int d2 = DY / dy;
	if(abs(d1-d2)%2==0){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
