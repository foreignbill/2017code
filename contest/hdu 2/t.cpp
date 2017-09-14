#include <iostream>
#include <math.h>
using namespace std;
#define LL long long
LL n, t;
double p, q;
LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void polya()
{
    for (LL i = 1; i <= n; i++)
        p += pow(1.0 * t, gcd(i, n)); //旋转循环数，顺时针旋转i格
    q = p;
    if (n % 2 == 0)
    {
        q += n / 2 * pow(1.0 * t, n / 2) + n / 2 * pow(1.0 * t, n / 2 + 1); //翻转，点数为偶数，分为由经过点和没经过点
    }
    else
    {
        q += n * pow(1.0 * t, n / 2 + 1); //翻转，点个数为奇数时，对称线经过一个点
    }
    p = p / n;
    q = q / (2 * n);
}
int main()
{
    while (cin >> n >> t)
    {
        p = 0, q;
        polya();
        cout << (LL)p << " " << (LL)q << endl;
    }
    return 0;
}
// 循环数，以6格点为例，记点为  1,2,3,4,5,6
//  翻转1：以1,2中间点翻转：得到 2,1,6,5,4,3
//  其中1->2,2->1成一个循环，共三个
// 翻转2：经过1,4的对称线翻转： 1,6,5,4,3,2
//循环为(1)(2,6)(3,5)(4)四个
//旋转：最大公约数就是循环数
// 最后本质不同数（即旋转和翻转后一样的都不要）为1/|G|*（∑颜色数^旋转i循环数+∑颜色数^翻转循环数）
//其中|G|为变换的总数，旋转n种，翻转n种

