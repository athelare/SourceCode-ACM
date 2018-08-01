#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 1005
#define Mod 1000000
int n,m,s,e;
int a[MAXN];

int dp[MAXN][100010];

void solve(){
    for(int i=0;i<=n;++i)dp[i][0] = 1;


    for(int i=0;i<n;++i){
        for(int j=1;j<=m;++j){
            if(j-1-a[i]>=0){
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j] - dp[i][j-1-a[i]] + Mod)%Mod;
            }else{
                dp[i+1][j] = (dp[i+1][j-1] + dp[i][j])%Mod;
            }
        }
    }
    int ans=0;
    //for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)printf("%d%c",dp[i][j],j==m?'\n':' ');
    for(int i=s;i<=e;++i)ans=(ans + dp[n][i])%Mod;
    printf("%d\n",ans);
}
int main(int argc, char const *argv[])
{
    int index;
    while(cin>>n>>m>>s>>e){
        fill(a,a+n,0);
        for(int i=0;i<m;++i){
            scanf("%d",&index);
            a[index-1]++;
        }
        solve();
    }
    return 0;
}
