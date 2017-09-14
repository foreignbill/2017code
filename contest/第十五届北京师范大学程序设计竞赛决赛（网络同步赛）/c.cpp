#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

string st;

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>st;
		int i=0;
		while(i<st.size()){
			if(st[i]=='0' || st[i]=='2' || st[i]=='4' || st[i]=='6' || st[i]=='9'){
				putchar(st[i]);
				i++;
				continue;
			}
			if(st.substr(i,4) == "zero"){
				putchar('0');
				i+=4;
				continue;
			}
			if(st.substr(i,3) == "two"){
				putchar('2');
				i+=3;
				continue;
			}
			if(st.substr(i,4) == "four"){
				putchar('4');
				i+=4;
				continue;
			}
			if(st.substr(i,3) == "six"){
				putchar('6');
				i+=3;
				continue;
			}
			if(st.substr(i,4) == "nine"){
				putchar('9');
				i+=4;
				continue;
			}
			i++;
		}
		puts("");
	}
	return 0;
} 
