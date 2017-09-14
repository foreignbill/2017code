#include <bits/stdc++.h>

using namespace std;

int d;

int main(){
	cin>>d;
	if(d==100){
			puts("+-----+");
			puts("|-  4G|");
			puts("|--   |");
			puts("|---  |");
			puts("|---- |");
			puts("|-----|");
			puts("+-----+");	
	}
	else if(d>=90){
			puts("+-----+");
			puts("|-  4G|");
			puts("|--   |");
			puts("|---  |");
			puts("|---- |");
			puts("|     |");
			puts("+-----+");	
	}
	else if(d>=80){
			puts("+-----+");
			puts("|-  3G|");
			puts("|--   |");
			puts("|---  |");
			puts("|---- |");
			puts("|     |");
			puts("+-----+");
	}
	else if(d>=60){
			puts("+-----+");
			puts("|-  3G|");
			puts("|--   |");
			puts("|---  |");
			puts("|     |");
			puts("|     |");
			puts("+-----+");
	}
	else if(d>=40){
			puts("+-----+");
			puts("|-   E|");
			puts("|--   |");
			puts("|     |");
			puts("|     |");
			puts("|     |");
			puts("+-----+");
	}
	else if(d>=20){
			puts("+-----+");
			puts("|-   E|");
			puts("|     |");
			puts("|     |");
			puts("|     |");
			puts("|     |");
			puts("+-----+");
	}
	else {
			puts("+-----+");
			puts("|    E|");
			puts("|     |");
			puts("|     |");
			puts("|     |");
			puts("|     |");
			puts("+-----+");
	}
	return 0;
} 
