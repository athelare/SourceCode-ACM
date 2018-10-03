#include<iostream>
#include<cstdio>
#define cost (11*Y - 9*X)
#define earn (11*X)
using namespace std;
int main()
{
    int T,t=0,X,Y,K,ans;
    scanf("%d",&T);
    while(t++<T){
        scanf("%d%d%d",&X,&Y,&K);
        if(X>Y){
            ans = K;
        }else{
            ans = (11*K*X)/(11*Y+2*X);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}