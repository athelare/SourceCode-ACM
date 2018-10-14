#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int T, n, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%d", &a);
        b=a;
        n--;
        while (n--)
            scanf("%d", &b);
        printf("%d\n",(int)(sqrt((int)fabs(a-b))));
    }
    return 0;
}