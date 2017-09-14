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
    //varStr[][0]变量名
    //varStr[][1]变量存储的内容
    string inputStr[101], outputStr[102], varStr[102][2], tempVar;
    cin >> n >> m;
    getchar();//吃掉一个回车符
    //这里之所以使用getline(cin,str)是因为每次可以读取一行数据，空格也不作为读取结束的标志。
    //如果用cin>>str的话，遇到空格则表示数据读取结束。
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
        //flag表示var变量是否存在定义
        bool flag = true;
        while (1)
        {
            flag = false;
            start = inputStr[i].find("{{ ");
            end = inputStr[i].find(" }}");
            if (start<0 || end<0) break; //若未找到"{{ "或者" }}",则退出循环 
            tempVar = inputStr[i].substr(start + 3, end - start - 3);//取出变量的值如name
            for (j = 0; j<m; j++)
            {
                if (tempVar == varStr[j][0])
                {
                    flag = true;
                    tempVar = varStr[j][1];
                    break;
                }
            }
            //不存在定义
            if (flag == false) tempVar = "";
            outputStr[i] = outputStr[i] + inputStr[i].substr(0, start) + tempVar;
            inputStr[i] = inputStr[i].substr(end + 3, inputStr[i].length() - end - 3);
        }
        outputStr[i] = outputStr[i] + inputStr[i];//不要忘了加上最后剩下的一截输入
        cout << outputStr[i] << endl;
    }
    return 0;
}
*/
