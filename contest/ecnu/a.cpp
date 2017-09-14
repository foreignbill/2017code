#include <cstdio>
#include <cstring>
#include <iostream>
#include <string> 

using namespace std;

bool isnum(char st){
	if('0'<=st&&st<='9') return 1;
	return 0;
}

int main(){
	freopen("input.txt","r",stdin);
	int T;
	string st;
	cin>>T;
	for(int id=1;id<=T;id++){
		printf("Case %d: ",id);
		cin>>st;
		int len = st.size();
		if( !isnum(st[len-1]) ){
			cout<<st<<endl;
			continue;
		}
		int t = st[len-1] - '0';
		bool find1 = 0;
		for(int i=0;i<len;i++){
			if(st[i]=='a'){
				if(t==1) st[i] = 'x0101';
				if(t==2) st[i] = 'ив';
				if(t==3) st[i] = 'иг';
				if(t==4) st[i] = 'ид';
				find1 = 1;
				break;
			}
		}
		bool find2 = find1;
		if(!find2){
			for(int i=0;i<len;i++){
				if(st[i]=='o'){
					if(t==1) st[i] = 'ин';
					if(t==2) st[i] = 'ио';
					if(t==3) st[i] = 'ип';
					if(t==4) st[i] = 'и░';
					find2 = 1;
					break;
				}
				if(st[i]=='e'){
					if(t==1) st[i] = 'ие';
					if(t==2) st[i] = 'иж';
					if(t==3) st[i] = 'из';
					if(t==4) st[i] = 'ии';
					find2 = 1;
					break;
				}
			}
		}
		bool find3 = find2;
		if(!find3){
			for(int i=0;i<len;i++){
				if(st[i]=='i'){
					if(t==1) st[i] = 'ий';
					if(t==2) st[i] = 'ик';
					if(t==3) st[i] = 'ил';
					if(t==4) st[i] = 'им';
					find3 = 1;
					break;
				}
				if(st[i]=='u'){
					if(t==1) st[i] = 'и▒';
					if(t==2) st[i] = 'и▓';
					if(t==3) st[i] = 'и│';
					if(t==4) st[i] = 'и┤';
					find3 = 1;
					break;
				}
			}
		}
		bool find4 = find3;
		if(!find4){
			for(int i=0;i<len;i++){
				if(st[i]=='v'){
					if(t==1) st[i] = 'и╡';
					if(t==2) st[i] = 'и╢';
					if(t==3) st[i] = 'и╖';
					if(t==4) st[i] = 'и╕';
					find3 = 1;
					break;
				}
			}
		}
		cout<<st<<endl; 
	}
	return 0;
}
