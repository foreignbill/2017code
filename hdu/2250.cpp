#include<iostream>
#include<fstream> //��������ļ��� 
#include<cstdio>
#include<cmath>
#define M 4 #define N 5 
using namespace std; 
double pow(double x,double y);
int main(){ 
 ifstream fs("d:\\file.txt",ios::in|ios::out);  //��д��ʽ���ļ�file.txt  
 while(fs.good ())
 cout<<(char)fs.get ();  //����ļ�   fs.close ();
 cout<<endl; 
  pow(2,31); //����pow()����   float max; //��ʱ����һ��ֵ   max=pow(2,31)-1;  float n;  //��ʼ�е�Ǯ��  int m;   //m��һ���ϵ  int i;   //����ѭ��  
 cout<<"������n,m��n��m��С�ڵ���10000"<<endl;  scanf("%f%d",&n,&m);  printf("n=%.0f,m=%d\n",n,m); start: 
 if(n>10000||m>10000)  { 
  printf("��������ݲ����Ϲ涨!\n");     printf("����������n��m��ֵ\n");         scanf("%f%d",&n,&m);   printf("n=%.0f,m=%d\n",n,m);   goto start;  }  else  { 
  printf("����������%d����Ʒ���ּ���Ӧ��Ʒ֮��һ���ϵ
�ҹ�ϵ�������ڵ���1С�ڵ���2\n",m);  }  if(m==4)  { 
  int a[N],b[N];   float w[N];   for(i=1;i<=m;i++)   { 
   scanf("%d",&a[i]);  //������Ʒ����    scanf("%d",&b[i]);  //������Ʒ����    scanf("%f",&w[i]);  //������Ʒ�һ�����   }    
  n=n*w[1]; 
  int j;  //����ѭ�� 
  float temp,temp1,temp2;  //���ڽ�����ֵ   temp=n; 
  for(j=1;j<N-2;j++)    { 
    if(b[j]==a[j+2])     { 
     n=n*w[j+1];
temp1=n;      }    } 
  for(j=1;j<N-3;j++)   { 
   if(b[j]==a[j+2])    { 
    n=temp;     n=n*w[j+2];     temp2=n;    }       } 
  if(temp1>=temp2)    n=temp1;   else    n=temp2;   if(n<max)   { 
   printf("%.2f\n",n);  //���׬��Ǯ��    printf("��������\n");    printf("׬��Ǯ��!\n");
  }   else   { 
   printf("�������Χ.\n");   }  }  else  { 
    int a[M],b[M];     float w[M];     for( i=1;i<=m;i++)   { 
   scanf("%d",&a[i]);  //������Ʒ����     scanf("%d",&b[i]);  //������Ʒ����    scanf("%f",&w[i]);    }   n=n*w[1];   int j; 
  for(j=1;j<M-1;j++)   { 
    if(b[j]==a[j+1])      n=n*w[j+1];
else     {      break;     }   }   if(n<max)   { 
   printf("%.2f\n",n);  //���׬��Ǯ��    printf("��������\n");    printf("׬��Ǯ��!\n");   }   else   { 
   printf("�������Χ.\n");   }  } 
 return  0; }
