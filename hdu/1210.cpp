#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int flat=1;int k=1;int s=0;
		while(1){
			s++;
			if(flat){
				k=2*k;
				if(k>n){
					k-=n;flat=0;
					if(k==1)break;
				}
			}
			else{
				k=2*(k-1)+1;
				if(k<=n){flat=1;}
				else{
					k-=n;
					if(k==1)break;
				}
			}
		}
		cout<<s+1<<endl;
	}
}
