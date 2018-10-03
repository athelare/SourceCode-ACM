#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int T,N,sum,i;
    char str[1000005],seed;
    scanf("%d",&T);
    while(T--){
        scanf("%d %c %s",&N,&seed,str);
        i=0;
        //跳过前导零字符
        while(seed == str[i] && i<N){
            i++;
            continue;
        }
        sum=0;
        
        //判断首位有无前导零
        if(i<N && abs(str[i]-seed) < 10)sum+=1;
        else if(i<N && abs(str[i]-seed) >= 10)sum+=2;
        if(i == N)printf("1\n");
        else printf("%d\n",sum+(N-i-1)*2);
    }
    return 0;
}