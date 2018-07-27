#include<cstdio>
#define MAXN 1000002
#define mod 1000000000
int dp[MAXN];

int main()
{
    int n;
    dp[1] = 1;
    dp[2] = 2;
    scanf("%d",&n);
    for(int i=3;i<=n;++i){
        dp[i] = (dp[i -1] )% mod;
        ++i;
        dp[i] = (dp[i-1] + dp[i>>1] )% mod;
    }
    printf("%d\n",dp[n]);
    return 0;
}