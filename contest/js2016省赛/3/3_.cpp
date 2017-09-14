#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int p[][4]={{},
				 {0,1,2,3},
				 {0,1,3,6},
				 {0,1,4,11},
				 {0,1,6,24},
				 {0,1,8,51},
				 {0,1,14,130},
				 {0,1,20,315},
				 {0,1,36,834},
				 {0,1,60,2195},
				 {0,1,108,5934}};

int main(){
	int T,n,k;
	cin>>T;
	for(int id=1;id<=T;id++){
		cin>>n>>k;
		printf("Case #%d: %d\n",id,p[n][k]);
	}
	return 0;
} 
