#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int dp[MAXN],a[MAXN],n,k;
void solve()
{
    fill(dp,dp+n,INF);
    for(int i=0;i<n;++i){
        *lower_bound(dp,dp+n,a[i])=a[i];
    }
    int up = lower_bound(dp,dp+n,INF)-dp;
    for(int i=0;i<n/2;++i){
        swap(a[i],a[n-1-i]);
    }
    fill(dp,dp+n,INF);
    for(int i=0;i<n;++i){
        *lower_bound(dp,dp+n,a[i])=a[i];
    }
    up = max(up,(int)(lower_bound(dp,dp+n,INF)-dp));
    puts(up>=(n-k)?"A is a magic array.":"A is not a magic array.");
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
        solve();
    }
    return 0;
}