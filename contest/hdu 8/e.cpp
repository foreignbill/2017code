#include<iostream>

using namespace std;

int main(){
	int t;
	int N,p,q;
	while(~scanf("%d%d%d",&N,&p,&q)){
		if(N<p){
			cout<<"Lose"<<endl;
		}
		else {
			if( N % (p + q) ==0 ) cout<<"WIN"<<endl;
			if( N % (p + q) ){
				if( N % (p + q) > p ) cout<<"WIN"<<endl;
				if( N % (p + q) <= p) cout<<"LOSE"<<endl;
			}
		}
	}
	return 0;
}

