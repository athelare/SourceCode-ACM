#include<stdio.h>
int main()
{
    int n, m,a,b,i;
    int min;
    while (~scanf("%d%d", &n, &m))
    {
        for (i = 0,min = 0x7f7f7f7f; i < m;++i){
            scanf("%d%d", &a, &b);
            if(b-a+1 < min)
                min = b - a + 1;
        }
        printf("%d\n0",min);
        for (int i = 1; i < n; ++i)
        {
            printf(" %d", i % min);
        }
        printf("\n");
    }
}
