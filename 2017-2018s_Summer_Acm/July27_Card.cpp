#include<iostream>
#include<cstdio>
using namespace std;

int n;
long long addV[1000005];
void solve()
{
    long long curSum=0;
    int maxIndex=0;
    for(int i=1;i<=n;++i){
        curSum+=addV[i];
        if(curSum<0){
            maxIndex=i;
            curSum=0;
        }
    }
    printf("%d\n",maxIndex);
}
int main()
{
    long long tmp;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i){
            scanf("%lld",&addV[i]);
        }
        for(int i=1;i<=n;++i){
            scanf("%lld",&tmp);
            addV[i]-=tmp;
        }
        solve();
    }
    return 0;
}

