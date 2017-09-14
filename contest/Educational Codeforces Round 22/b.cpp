#include <bits/stdc++.h>

#define LL long long

using namespace std;

const LL inf = 1000000000000000000LL;
const LL inf_2 = 1000000000LL;

LL x,y,l,r; 

set<LL> S;

LL pow(LL a,LL b){
	if(b==0){
		LL ans=1;
		return ans;
	} else {
		LL ans=1;
		for(LL i=1;i<=b;i++){
			ans*=a;
			if(ans>r) return -1;
		}
		return ans;
	}
}

int main(){
	cin>>x>>y>>l>>r;
	S.clear();
	for(int i=0;i<=63;i++)
		for(int j=0;j<=63;j++){
			LL a=pow(x,i);
			LL b=pow(y,j);
			if(a==-1||b==-1)break;
			LL t = pow(x,i) + pow(y,j);
			S.insert(t);
		}
	LL mx=0;
	set<LL>::iterator its=S.lower_bound(l);
	set<LL>::iterator its2=its;its2++;its2++;
	mx = (*its) - l;
	its++;
	for(;its!=S.end()&&its2!=S.end();its++,its2++){
		if((*its2)>r) break;
		LL tmp = (*its2) - (*its) - 1;
		if(tmp>mx)
			mx=tmp;
	}
	if((*its)<r){
		LL tmp = r - (*its);
		if(tmp>mx)
			mx=tmp;
	}
	cout<<mx<<endl;
	return 0; 
} 
