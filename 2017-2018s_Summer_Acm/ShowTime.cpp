#include<cstdio>

int main()
{
    int h,m,ms;
    while(~scanf("%d:%d %d",&h,&m,&ms)){
        m = m+ms;
        h+=m/60;
        m%=60;
        h%=24;
        if(h<10)printf("0");
        printf("%d:",h);
        if(m<10)printf("0");
        printf("%d\n",m);
    }
    return 0;
}
