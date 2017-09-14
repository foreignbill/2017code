#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,i,j,m;
ll sum1,sum2,ans;
const double PI = atan(1.0)*4.0;
const double eps = 1e-6;
struct node{
	int x,y,v;
	double d;
}info[50010];

bool cmp(node A,node B){
	return A.d<B.d;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        sum1=0;sum2=0;ans=0;
        for(i=0;i<n;i++){
            scanf("%d%d%d",&info[i].x,&info[i].y,&info[i].v);
            info[i].d=atan2(info[i].y,info[i].x);
            sum1+=info[i].v;
        }
        sort(info,info+n,cmp);
        for(i=0;i<n;i++){
            if(info[i].d>0) break;
            sum1-=info[i].v;sum2+=info[i].v;
        }
        m=i;j=0;
        while(j<m && i<n){
            if(fabs(info[i].d-info[j].d-PI)<eps){
                sum1-=info[i].v;sum2+=info[i].v;
                i++;
                while(i<n && fabs(info[i].v-info[i-1].v)<eps){
                    sum1-=info[i].v;sum2+=info[i].v;
                    i++;
                }
                sum2-=info[j].v;sum1+=info[j].v;
                j++;
                while(j<m && fabs(info[j].v-info[j-1].v)<eps){
                    sum2-=info[j].v;sum1+=info[j].v;
                    j++;
                }
            } else if(info[i].d-info[j].d>PI){
                sum2-=info[j].v;sum1+=info[j].v;
                j++;
                while(j<m && fabs(info[j].v-info[j-1].v)<eps){
                    sum2-=info[j].v;sum1+=info[j].v;
                    j++;
                }
            } else {
                sum1-=info[i].v;sum2+=info[i].v;
                i++;
                while(i<n && fabs(info[i].v-info[i-1].v)<eps){
                    sum1-=info[i].v;sum2+=info[i].v;
                    i++;
                }
            }
            ans=max(ans,sum1*sum2);
        }
        while(i<n){
            sum1-=info[i].v;sum2+=info[i].v;
            i++;
            while(i<n && fabs(info[i].v-info[i-1].v)<eps){
                sum1-=info[i].v;sum2+=info[i].v;
                i++;
            }
            ans=max(ans,sum1*sum2);
        }
        while(j<m){
            sum2-=info[j].v;sum1+=info[j].v;
            j++;
            while(j<m && fabs(info[j].v-info[j-1].v)<eps){
                sum2-=info[j].v;sum1+=info[j].v;
                j++;
            }
            ans=max(ans,sum1*sum2);
        }
        printf("%lld\n",ans);
    }
    return 0; 
}
