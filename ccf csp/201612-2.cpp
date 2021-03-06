#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

double calc(int c){
	if(c<=3500) return 0;
	int A = c-3500;
	if(A<=1500) return A*0.03;
	if(A<=4500) return 1500*0.03+(A-1500)*0.1;
	if(A<=9000) return 1500*0.03+(4500-1500)*0.1+(A-4500)*0.2;
	if(A<=35000) return 1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(A-9000)*0.25;
	if(A<=55000) return 1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(A-35000)*0.3;
	if(A<=80000) return 1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(A-55000)*0.35;
	return 1500*0.03+(4500-1500)*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(80000-55000)*0.35+(A-80000)*0.45;
}

int main(){
	int n;
	scanf("%d",&n);
	double ans = 0;
	for(int i=1;i<=10000000;i++){
		int t = i;
		if(fabs(t-calc(t)-n)<0.00001){
			printf("%d\n",t);
			break;
		}
	}
	return 0;
} 
