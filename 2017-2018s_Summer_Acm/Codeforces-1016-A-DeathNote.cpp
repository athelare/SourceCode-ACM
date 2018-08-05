#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    long long  n,m,curPage=0,tmp;
    int i;
    cin>>n>>m;
    for(i=0;i<n;++i){
        scanf("%I64d",&tmp);
        if(curPage+tmp >= m){
            printf("%I64d ",(curPage+tmp)/m);
            curPage = (curPage+tmp)%m;
        }else{
            printf("0 ");
            curPage+=tmp;
        }
    }
    return 0;
}