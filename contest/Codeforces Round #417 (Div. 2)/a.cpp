#include <bits/stdc++.h>

using namespace std;

struct node{
	int l,s,r,p;
}a[44];

int main(){
	for(int i=0;i<4;i++){
		scanf("%d%d%d%d",&a[i].l,&a[i].s,&a[i].r,&a[i].p);
	}
	bool ok=true; 
	for(int i=0;i<4;i++){
		if( (a[i].l||a[i].s||a[i].r) && (a[i].p) )
			ok=0;
		if( (a[i].l) && (a[(i+3)%4].p) )
			ok=0;
		if( (a[i].r) && (a[(i+1)%4].p) )
			ok=0;
	}
	puts(ok?"NO":"YES");
	return 0;
} 
