#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long d, pa[3][500005],*a=pa[0],*b = pa[1],*c = pa[2];
long long n[3],&na = n[0], &nb=n[1], &nc=n[2];
int main()
{
    ios::sync_with_stdio(false);

    while (cin>>d>>na>>nb>>nc)
    {
        for (int i=0; i<3; i++)
        for (int j=0; j<n[i]; j++)
            cin >> pa[i][j];
        long long sum=0;
        for (int j=0; j<na; j++)
            sum+=
            (long long)(upper_bound(b, b+nb, a[j]+d)-upper_bound(b, b+nb, a[j])) *
            (long long)(upper_bound(c, c+nc, a[j]+d)-upper_bound(c, c+nc, a[j]));
        for (int j=0; j<nb; j++)
            sum+=
            (long long)(upper_bound(a, a+na, b[j]+d)-lower_bound(a, a+na, b[j])) *
            (long long)(upper_bound(c, c+nc, b[j]+d)-upper_bound(c, c+nc, b[j]));
        for (int j=0; j<nc; j++)
            sum+=
            (long long)(upper_bound(b, b+nb, c[j]+d)-lower_bound(b, b+nb, c[j])) *
            (long long)(upper_bound(a, a+na, c[j]+d)-lower_bound(a, a+na, c[j]));
        cout<<sum<<endl;
    }
    return 0;
}
/* 思路：在三个数组中选一个枚举，被枚举的那个数组中的每个元素看作三元组中的最小元素，
这样另外两个数组都是寻找[k, k+d]范围内的数字，两次二分查找（k指代被扫的数组中的元素）
因为后两个数组是分步操作所以乘法原理乘起来
这样枚举三个数组就分别得到了三个数组中各自元素为最小时的所有情况，加起来就是答案。

这样会产生的问题是，如果是数组1中元素=数组2中元素这种情况会重复加。
解决办法是，设定一个偏序，比如扫数组1的时候，数组2和数组3的元素必须严格大于数组1元素
扫数组2的时候，数组1元素可以等于数组2元素，数组3元素必须大于数组2元素
扫数组3的时候，1和2都可以取等号
然后在test10的时候wa了，好像是个大数据的样例，但是看起来操作中也没有爆long long的过程

难受
orz

*/
