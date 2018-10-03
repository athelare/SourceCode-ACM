#include<cstdio>
#include<cmath>
int main()
{
    int T,n,i=0;
    scanf("%d",&T);
    while(i++<T){
        scanf("%d",&n);
        int sum=0,tmp;
        for(int j=0;j<n;++j){
            scanf("%d",&tmp);
            sum+=tmp+(int)ceil((double)tmp/10.0);
        }
        printf("Case #%d: %d\n",i,sum);
    }
    return 0;
}