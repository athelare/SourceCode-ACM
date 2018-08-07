#include<stdio.h>
#include<string.h>
#define MAXN 32001
int Ans[MAXN];
int BIT[MAXN+1];
void add(int i){
    while(i<=MAXN){
        BIT[i]++;
        i+=(i & (-i));
    }
}
int sum(int i){
    int ans=0;
    while(i>0){
        ans+=BIT[i];
        i-=i&(-i);
    }
    return ans;
}

int main()
{
    int i,tmp,dr,n;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d%d",&tmp,&dr);
        tmp++;
        Ans[sum(tmp)]++;
        add(tmp);
    }
    for(i=0;i<n;++i)printf("%d\n",Ans[i]);
    return 0;
}
