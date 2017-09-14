#include <cstdio>
#include <cstring>

using namespace  std;

struct node {
	int x1,y1,x2,y2;
}point[111]; 

int main() {
	int n;
	while(~scanf("%d",&n)) {
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d%d",&point[i].x1,&point[i].y1,&point[i].x2,&point[i].y2);
		}
		int minx=point[1].x1,tp1;
		for(int i=1;i<=n;i++)
			if( minx > point[i].x1 ) {
				minx = point[i].x1;
			}
		int miny = 60000;
		for(int i=1;i<=n;i++)
			if( minx == point[i].x1 && miny > point[i].y1 ) {
				miny = point[i].y1;
				tp1 = i;
			}
		int maxx=point[1].x2,tp2;
		for(int i=1;i<=n;i++)
			if( maxx < point[i].x2 ) {
				maxx = point[i].x2;
			}
		int maxy = 0;
		for(int i=1;i<=n;i++)
			if( maxx==point[i].x2 && maxy < point[i].y2 ) {
				maxy =point[i].y2;
				tp2 = i; 
			}
		
		bool check1 = 1;
		for(int i=1;i<=n;i++) {
			check1 = check1 && ( ( minx<=point[i].x1 && point[i].x2<=maxx ) && ( miny<=point[i].y1 && maxy>=point[i].y2 ) );
		}
		
		bool check2 = 0;
		for(int i=1;i<=n;i++) {
			check2 = check2 || ( ( minx >= point[i].x1 && minx <= point[i].x2 ) && ( point[i].y1 <= miny && miny <= point[i].y2 ) );
		}
		
		bool check3 = 0;
		for(int i=1;i<=n;i++) {
			check3 = check3 || ( ( minx >= point[i].x1 && minx <= point[i].x2 ) && ( point[i].y1 <= maxy && maxy <= point[i].y2 ) );
		}
		
		bool check4 = 0;
		for(int i=1;i<=n;i++) {
			check4 = check4 || ( ( maxx >= point[i].x1 && maxx <= point[i].x2 ) && ( point[i].y1 <= maxy && maxy <= point[i].y2 ) );
		}
		
		bool check5 = 0;
		for(int i=1;i<=n;i++) {
			check5 = check5 || ( ( maxx >= point[i].x1 && maxx <= point[i].x2 ) && ( point[i].y1 <= miny && miny <= point[i].y2 ) );
		}
		
		puts(check1&&check2&&check3&&check4&&check5?"YES":"NO");
	}
	
	return 0;
} 
