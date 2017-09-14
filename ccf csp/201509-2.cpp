#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int days1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const int days2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
	int year,day;
	scanf("%d%d",&year,&day);
	int month=1,date=0;
	if(year%400==0 || (year%100!=0&&year%4==0) ){
		while(day--){
			date++;
			if(date==days2[month]+1){
				month++;
				date=1;
			}
		}
	} else {
		while(day--){
			date++;
			if(date==days1[month]+1){
				month++;
				date=1;
			}
		}
	}
	printf("%d\n%d\n",month,date);
	return 0;
} 
