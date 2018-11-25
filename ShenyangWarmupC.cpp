
#include <stdio.h>
#include <time.h>
const int mod = 1000000007;
int dp[31][901],C[31][31];
int main()
{
    time_t st,end;
    st = clock();
    int n = 30, m = 900;
    for (int i = 1; i <=n ; i++) {
        C[i][i] = C[i][0] =1;
    }

    for (int i = 1; i <=n ; i++) {
        for (int j = 1; j <i ; j++) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) %mod;
        }
    }
    dp[0][0]= dp[1][1] = 1;
    for (int i = 2; i <=n ; i++) {
        for (int k1 = 0; k1 <=m ; k1++) {
            for (int k2 = 0; k1+k2 <=m ; k2++) {
                for (int j = 0; j <i ; j++) {
                    int tmp = (long long )dp[j][k1] *dp[i-j-1][k2] %mod *C[i-1][j] %mod;
                    dp[i][k1+k2+i] = (dp[i][k1+k2+i] + tmp) %mod;
                }
            }
        }
    }
    end = clock();
    printf("%f\n", (double)(end -st)/CLOCKS_PER_SEC);
    int k;
    while(~scanf("%d %d",&n,&k))printf("%d\n",dp[n][k]);

}