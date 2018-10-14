#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 5 * 100000 + 5
using namespace std;
int a[MAXN], b[MAXN], c[MAXN];
int main()
{
    int d, na, nb, nc, i, j;
    int cal, cau, cbl, cbu;
    long long ans;
    while (~scanf("%d%d%d%d", &d, &na, &nb, &nc))
    {
        for (i = 0; i < na;++i)scanf("%d", &a[i]);
        for (i = 0; i < nb;++i)scanf("%d", &b[i]);
        for (i = 0; i < nc;++i)scanf("%d", &c[i]);
        ans = 0;
        int as = 0, ae = 0;
        for (i = 0; i < na; ++i)
        {
            while(b[as]<a[i]-d && as < nb)as++;
            while(b[ae]<=a[i]+d && ae < nb)ae++;
            for (j = as; j < ae; ++j)
            {
                cal = lower_bound(c, c + nc, a[i] - d) - c;
                cau = upper_bound(c, c + nc, a[i] + d) - c;
                cbl = lower_bound(c, c + nc, b[j] - d) - c;
                cbu = upper_bound(c, c + nc, b[j] + d) - c;
                ans += min(cau, cbu) - max(cal, cbl);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}