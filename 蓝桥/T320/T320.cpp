#include<stdio.h>
int a[1000];
double num[1000],temp[1000];
int top;
int binary_search(double x){
    int l=0,r=top,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(temp[mid]>=x) r=mid-1;
        else{
            l=mid;
            if(temp[l+1]>=x)return l+1;
            else l++;
        }
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    	num[i] = a[i] + 1.0 * i / 1000;
    top=0;temp[0]=num[0];
    for(i=1;i<n;i++){
        if(num[i]>temp[top]) temp[++top]=num[i];
        else{
            if(num[i]<=temp[0]) temp[0]=num[i];
            else  temp[binary_search(num[i])]=num[i];
        }
    }
    printf("%d\n",top+1);
    return 0;
}
