#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int p=0,x=0,a;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			x^=a;
			p+=(a>1);
		}
		if( (p==0&&n&1) || (p>1&&x==0) ) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
/*
Nim ���� 
�����жѶ�Ϊ1��SGֵΪ0������ż����ʯ�ӣ�������ʤ�� 
i)ֻ��һ��ʯ��������1ʱ�������ܿ��ԶԸ�ʯ�Ӳ�����ʹ���������Ϊ���������жѵ�ʯ������Ϊ1�� 

ii)�г���һ�ѵ�ʯ����1ʱ�����ֽ�SGֵ��Ϊ0���ɣ����ܻ�����ĳ��ʯ��������1 
*/
