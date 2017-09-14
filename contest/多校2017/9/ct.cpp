#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int maxn = 2600 + 10;
char ar[maxn], sa[maxn];
int main()
{
    int i, j, k, u, n, m;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%s", ar);
            scanf("%s", sa);
            int L1 = strlen(ar);
            int L2 = strlen(sa);
            i = 0;
            j = 0;
            int doudou = 1;
            while(i < L1 && j < L2)
            {
                if(ar[i] == sa[j])
                {
                    i++;
                    j++;
                }
                else if(sa[j] == '.')
                {
                    sa[j] = ar[i];
                    i++;
                    j++;
                }
                else if(ar[i] != sa[j] && sa[j+1] == '*')
                {
                    j += 2;
                }
                else if(sa[j] == '*')
                {
                    if(ar[i] == sa[j-1])
                        i++;
                    else
                    {
                        j++;
                    }
                }
                else 
                {
                    doudou = 0;
                    break;
                }
            }
            if(i == L1)
            {
                for(; j < L2; j++)
                {
                    if(sa[j] != '*' && sa[j+1] != '*')
                    {
                        doudou = 0;
                        break;
                    }
                }
            }
            else
            {
                doudou = 0;
            }
            if(doudou)
                printf("yes\n");
            else
                printf("no\n");
        }
    }
    return 0;
}
