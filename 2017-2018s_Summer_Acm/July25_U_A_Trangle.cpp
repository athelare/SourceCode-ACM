#include<cstdio>
#include<iostream>
using namespace std;

int N,*Row,*LastRow,triangle[355][355];

int main()
{
    int i,j;
    while(~scanf("%d",&N)){
        for(i=1;i<=N;++i){
            for(j=1;j<=i;++j){
                scanf("%d",&triangle[i][j]);
            }
        }
        for(i=N-1;i>0;--i){
            for(j=1;j<=i;++j){
                triangle[i][j] = triangle[i][j]+max(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        printf("%d\n",triangle[1][1]);
    }
    return 0;
}