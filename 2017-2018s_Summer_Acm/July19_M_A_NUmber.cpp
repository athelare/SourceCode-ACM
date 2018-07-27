#include<cstdio>
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
        printf("%d\n",n+k-n%k);
    return 0;
}
