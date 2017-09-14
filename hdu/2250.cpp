#include<iostream>
#include<fstream> //输入输出文件流 
#include<cstdio>
#include<cmath>
#define M 4 #define N 5 
using namespace std; 
double pow(double x,double y);
int main(){ 
 ifstream fs("d:\\file.txt",ios::in|ios::out);  //以写方式打开文件file.txt  
 while(fs.good ())
 cout<<(char)fs.get ();  //输出文件   fs.close ();
 cout<<endl; 
  pow(2,31); //调用pow()函数   float max; //临时储存一个值   max=pow(2,31)-1;  float n;  //开始有的钱数  int m;   //m组兑换关系  int i;   //用于循环  
 cout<<"请输入n,m且n和m都小于等于10000"<<endl;  scanf("%f%d",&n,&m);  printf("n=%.0f,m=%d\n",n,m); start: 
 if(n>10000||m>10000)  { 
  printf("输入的数据不符合规定!\n");     printf("请重新输入n和m的值\n");         scanf("%f%d",&n,&m);   printf("n=%.0f,m=%d\n",n,m);   goto start;  }  else  { 
  printf("下面请输入%d组物品名字及对应物品之间兑换关系
且关系比例大于等于1小于等于2\n",m);  }  if(m==4)  { 
  int a[N],b[N];   float w[N];   for(i=1;i<=m;i++)   { 
   scanf("%d",&a[i]);  //存入物品名称    scanf("%d",&b[i]);  //存入物品名称    scanf("%f",&w[i]);  //存入物品兑换比例   }    
  n=n*w[1]; 
  int j;  //用于循环 
  float temp,temp1,temp2;  //用于交换数值   temp=n; 
  for(j=1;j<N-2;j++)    { 
    if(b[j]==a[j+2])     { 
     n=n*w[j+1];
temp1=n;      }    } 
  for(j=1;j<N-3;j++)   { 
   if(b[j]==a[j+2])    { 
    n=temp;     n=n*w[j+2];     temp2=n;    }       } 
  if(temp1>=temp2)    n=temp1;   else    n=temp2;   if(n<max)   { 
   printf("%.2f\n",n);  //输出赚的钱数    printf("￥￥￥￥\n");    printf("赚大钱啦!\n");
  }   else   { 
   printf("超出最大范围.\n");   }  }  else  { 
    int a[M],b[M];     float w[M];     for( i=1;i<=m;i++)   { 
   scanf("%d",&a[i]);  //存入物品名称     scanf("%d",&b[i]);  //存入物品名称    scanf("%f",&w[i]);    }   n=n*w[1];   int j; 
  for(j=1;j<M-1;j++)   { 
    if(b[j]==a[j+1])      n=n*w[j+1];
else     {      break;     }   }   if(n<max)   { 
   printf("%.2f\n",n);  //输出赚的钱数    printf("￥￥￥￥\n");    printf("赚大钱啦!\n");   }   else   { 
   printf("超出最大范围.\n");   }  } 
 return  0; }
