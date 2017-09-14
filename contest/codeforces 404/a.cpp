#include <cstdio>
#include <string>
#include <map>
#include <iostream> 

using namespace std;

map<string,int> mp;

int main(){
	mp.clear();
	mp["Tetrahedron"]=4;
	mp["Cube"]=6;
	mp["Octahedron"]=8;
	mp["Dodecahedron"]=12;
	mp["Icosahedron"]=20;
	int n,ans=0;
	string st;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st;
		ans+=mp[st];
	}
	cout<<ans<<endl;
	return 0;
}
