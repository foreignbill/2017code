#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int n,m;

string st;
string info[111];

struct node{
	string A,B;
}transform[111];

int main(){
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++) getline(cin,info[i]);
	for(int i=1;i<=m;i++){
		cin>>transform[i].A;
		getline(cin,st);
		int len = st.size();
		transform[i].B=st.substr(2,len-3);
		//getline(cin,st);
		//int pos=st.find(' ');
		//int len=st.size();
		//for(int tp=0;tp<pos;tp++) transform[i].A+=st[tp];
		//transform[i].A=st.substr(0,pos);
		//cout<<"+"<<transform[i].A<<"+"<<endl;
		//for(int tp=pos+2;tp<strlen(st)-1;tp++) transform[i].B+=st[tp];
		//transform[i].B=st.substr(pos+2,len-1-pos-2);
		//cout<<"+"<<transform[i].B<<"+"<<endl;
		//cout<< transform[i].B <<endl;
	}
	
	for(int i=1;i<=n;i++){
		if(info[i].find("{{")==-1||info[i].find("}}")==-1){
			cout<<info[i];
			puts("");
			continue;
		}
		while(1){
			int tp1=info[i].find("{{"),tp2=info[i].find("}}");
			string Left = info[i].substr(0,tp1);
			string Right = info[i].substr(tp2+2);
			string Mid = info[i].substr(tp1+3,tp2-2-tp1-3+1); 
			//cout<<Left<<"*****"<<Mid<<"************"<<Right<<endl; 
			bool pan=false;
			for(int ii=1;ii<=m;ii++){
				if(Mid==transform[ii].A){
					Mid=transform[ii].B;
					pan=true;
					break;
				}
			}
			if(!pan) Mid="";
			info[i]=Left+Mid+Right;
			if(info[i].find("{{")==-1) break;
			if(info[i].find("}}")==-1) break;
		}
		cout<<info[i];
		puts("");
	}
	
	return 0;
} //80


/*
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int n, m, i, j, start,end;
    //varStr[][0]������
    //varStr[][1]�����洢������
    string inputStr[101], outputStr[102], varStr[102][2], tempVar;
    cin >> n >> m;
    getchar();//�Ե�һ���س���
    //����֮����ʹ��getline(cin,str)����Ϊÿ�ο��Զ�ȡһ�����ݣ��ո�Ҳ����Ϊ��ȡ�����ı�־��
    //�����cin>>str�Ļ��������ո����ʾ���ݶ�ȡ������
    for (i = 0; i < n; i++)
        getline(cin, inputStr[i]);
    for (i = 0; i<m; i++)
    {
        cin >> varStr[i][0];
        getline(cin, varStr[i][1]);
        start = varStr[i][1].find("\"");
        end = varStr[i][1].rfind("\"");
        varStr[i][1] = varStr[i][1].substr(start + 1, end - start - 1);
    }
    for (i = 0; i<n; i++)
    {
        //flag��ʾvar�����Ƿ���ڶ���
        bool flag = true;
        while (1)
        {
            flag = false;
            start = inputStr[i].find("{{ ");
            end = inputStr[i].find(" }}");
            if (start<0 || end<0) break; //��δ�ҵ�"{{ "����" }}",���˳�ѭ�� 
            tempVar = inputStr[i].substr(start + 3, end - start - 3);//ȡ��������ֵ��name
            for (j = 0; j<m; j++)
            {
                if (tempVar == varStr[j][0])
                {
                    flag = true;
                    tempVar = varStr[j][1];
                    break;
                }
            }
            //�����ڶ���
            if (flag == false) tempVar = "";
            outputStr[i] = outputStr[i] + inputStr[i].substr(0, start) + tempVar;
            inputStr[i] = inputStr[i].substr(end + 3, inputStr[i].length() - end - 3);
        }
        outputStr[i] = outputStr[i] + inputStr[i];//��Ҫ���˼������ʣ�µ�һ������
        cout << outputStr[i] << endl;
    }
    return 0;
}
*/
