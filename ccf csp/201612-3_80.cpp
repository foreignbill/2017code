#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;

int p,r,u,q,T;

string info[111],st1,st2,str,key;

map<string,vector<string> > mp;
map<string,vector<string> > mp2;
map<string,int> m;

vector<string> v;

int isin(string key,string st2){
	if(key==st2) return 1;
	int len1=key.size(),len2=st2.size();
	int tp1=key.find(":");
	string tmp1,tmp2;
	tmp1=key.substr(0,tp1);
	int tp2=st2.find(":");
	tmp2=st2.substr(0,tp2);
	if(tmp1!=tmp2) return 0;
	
	int num1=-1,num2=-1;
	if(key[len1-2]==':'){
		num1=key[len1-1]-'0';
	}
	if(st2[len2-2]==':'){
		num2=st2[len2-1]-'0';
	}
	if(num1==-1){
		return num2;
	}
	return num1<=num2;
}

int main(){
	freopen("input.txt","r",stdin);
	m.clear();
	mp.clear();
	mp2.clear();
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>info[i];
		m[info[i]]++;
	}
	cin>>r;
	for(int i=1;i<=r;i++){
		v.clear();
		cin>>st1>>T;
		for(int j=1;j<=T;j++){
			cin>>st2;
			v.push_back(st2); 
		}
		mp[st1]=v;
	}
	cin>>u;
	for(int i=1;i<=u;i++){
		v.clear();
		cin>>st1>>T;
		for(int j=1;j<=T;j++){
			cin>>st2;
			v.push_back(st2);
		}
		mp2[st1]=v;
	}
	cin>>q;
	for(int cnt=1;cnt<=q;cnt++){
		bool ok=false,pan=false;
		int maxlevel=0;
		cin>>st1>>st2;
		if(st2[st2.size()-2]!=':'){
			pan=true;
			maxlevel=0;
		}
		if(m[st2]){
			pan=false;
		}
		map<string,vector<string> >::iterator it1=mp2.begin();
		for(;it1!=mp2.end();it1++){
			if(it1->first!=st1) continue;
			for(int i=0;i<it1->second.size();i++){
				str=it1->second[i]; 
				map<string,vector<string> >::iterator it2=mp.begin();
				for(;it2!=mp.end();it2++){
					if(it2->first!=str) continue;
					for(int j=0;j<it2->second.size();j++){
						key=it2->second[j];
						int tt=isin(st2,key);
						if(tt){
							if(pan){
								bool p=true;
								if(key.find(':')!=key.size()){
									int num=key[key.size()-1]-'0';
									for(int c=1;c<=p;c++)
										if(info[c].find(key.substr(0,key.find(':')))!=info[c].size()){
											if(info[c].find(':')==info[c].size()) continue;
											int nn=info[c][info[c].size()-1]-'0';
											if(num>nn){
												p=false;
											}
										}
								}
								if(!p) continue;
								if(maxlevel<tt) maxlevel=tt;
								continue;
							}
							ok=true;
							break;
						}
					}
					if(ok) break;
				}
				if(ok) break;
			}
			if(ok) break;
		}
		if(!pan) puts(ok?"true":"false");
		else{
			if(maxlevel<=0) puts("false");
			else{
				printf("%d\n",maxlevel);
			}
		}
	}
	return 0;
}

