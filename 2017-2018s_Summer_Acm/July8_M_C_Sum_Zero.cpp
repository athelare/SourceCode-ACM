#include<iostream>
#include<cstdio>
#include<algorithm>
#define MXN 4004
using namespace std;

int n,A[MXN], B[MXN], C[MXN], D[MXN],SAB,SCD[MXN*MXN];
int main()
{
    int i;
    long long ans;
    while (~scanf("%d", &n))
    {
        for (i = 0; i < n;++i)
            scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
        i = 0;
        for (int j = 0; j < n;++j){
            for (int k = 0; k < n;++k)
                SCD[i++] = -C[j] -D[k];
        }
        sort(SCD, SCD + n * n);

        ans = 0;
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n;++k){
                SAB = A[j] + B[k];
                ans += upper_bound(SCD, SCD + n * n, SAB) - lower_bound(SCD, SCD + n * n, SAB);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}