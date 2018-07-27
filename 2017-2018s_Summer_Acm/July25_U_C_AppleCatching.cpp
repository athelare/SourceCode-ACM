#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 1002
int dp[MAXN][35];
int a[MAXN];
int T,W;

int main()
{
    cin>>T>>W;
    for(int i=1;i<=T;++i)cin>>a[i];
    dp[1][0] = a[1] == 1?1:0;
    dp[1][1] = 1-dp[1][0];
    for(int i=2;i<=T;++i){
        for(int j = 0;j<=W;++j){
            if(j==0){dp[i][j] = dp[i-1][j] + a[i]%2;}
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]);
                if(j%2+1 == a[i])dp[i][j]++;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=W;++i)
        ans = max(ans,dp[T][i]);
    printf("%d\n",ans);
    return 0;
}