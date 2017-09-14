#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool check(int hour,int min){
	int t1=hour/10;
	int t2=hour%10;
	int t3=min/10;
	int t4=min%10;
	if(t1!=t4) return 0;
	if(t2!=t3) return 0;
	return 1;
}

int main(){
	int hour,min;
	scanf("%d:%d",&hour,&min);
	if(check(hour,min)){
		puts("0");
		return 0;
	}
	for(int i=1;;i++){
		min++;
		if(min==60){
			hour++;
			min=0;
		}
		if(hour==24){
			hour=0;
		}
		if(check(hour,min)){
			printf("%d\n",i);
			return 0;
		}
	} 
	return 0;
} 
