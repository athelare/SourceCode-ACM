#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n;
    long long curNum, initialNum, last, p,loops;
    loops = 1;
    scanf("%d", &n);
    scanf("%lld", &curNum);
    p = initialNum = last = curNum;
    for (int i = 1; i < n; ++i){
        scanf("%lld", &curNum);
        if(curNum <= last){
            p = max(last, p);
            loops++;
        }else{
            p = max(p, curNum);
        }
        last = curNum;
    }
    switch(loops){
        case 1:{
            printf("%lld\n", p - initialNum + 1);
            break;
        }
        case 2:{
            printf("%lld\n", p - initialNum + curNum + 2);
            break;
        }
        default:{
            printf("%lld\n", (p + 1) * (loops - 2) + p - initialNum + curNum + 2);
            break;
        }
    }
    return 0;
}