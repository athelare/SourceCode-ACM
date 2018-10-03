#include<cstdio>
int main()
{
    int T,p;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&p);
        for(int i=1;i<=p;++i){
            for(int j=1;j<=p;++j){
                printf("0%c",j==p?'\n':' ');
            }
        }
        for(int i=1;i<=p;++i){
            for(int j=1;j<=p;++j){
                printf("%d%c",j == 2?(i == p?1:(i+j-2)%p):0,j==p?'\n':' ');
            }
        }
    }
    return 0;
}