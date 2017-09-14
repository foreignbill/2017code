#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>

using namespace std;
map<char,string> mp;
void init(){
	mp.clear();
	mp['A']=mp['a']="=.===";
	mp['B']=mp['b']="===.=.=.=";
	mp['C']=mp['c']="===.=.===.=";
	mp['D']=mp['d']="===.=.=";
	mp['E']=mp['e']="=";
	mp['F']=mp['f']="=.=.===.=";
	mp['G']=mp['g']="===.===.=";
	mp['H']=mp['h']="=.=.=.=";
	mp['I']=mp['i']="=.=";
	mp['J']=mp['j']="=.===.===.===";
	mp['K']=mp['k']="===.=.===";
	mp['L']=mp['l']="=.===.=.=";
	mp['M']=mp['m']="===.===";
	mp['N']=mp['n']="===.=";
	mp['O']=mp['o']="===.===.===";
	mp['P']=mp['p']="=.===.===.=";
	mp['Q']=mp['q']="===.===.=.===";
	mp['R']=mp['r']="=.===.=";
	mp['S']=mp['s']="=.=.=";
	mp['T']=mp['t']="===";
	mp['U']=mp['u']="=.=.===";
	mp['V']=mp['v']="=.=.=.===";
	mp['W']=mp['w']="=.===.===";
	mp['X']=mp['x']="===.=.=.===";
	mp['Y']=mp['y']="===.=.===.===";
	mp['Z']=mp['z']="===.===.=.=";
	mp['1']="=.===.===.===.===";
	mp['2']="=.=.===.===.===";
	mp['3']="=.=.=.===.===";
	mp['4']="=.=.=.=.===";
	mp['5']="=.=.=.=.=";
	mp['6']="===.=.=.=.=";
	mp['7']="===.===.=.=.=";
	mp['8']="===.===.===.=.=";
	mp['9']="===.===.===.===.=";
	mp['0']="===.===.===.===.===";
}

int main(){
	init();
	int T;
	cin>>T;
	for(int id=1;id<=T;id++){
		int n;
		string st;
		cin>>n;
		printf("Case #%d: ",id);
		for(int i=1;i<=n;i++){
			cin>>st;
			if(i>1) printf(".......");
			for(int j=0;j<st.size();j++){
				if(j>0) printf("...");
				cout<<mp[st[j]];
			}
		}
		puts("");
	}
	
	return 0;
} 
