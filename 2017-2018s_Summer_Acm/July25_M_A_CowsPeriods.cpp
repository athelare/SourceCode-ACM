#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Cow{
    int l,r;
    friend bool operator<(Cow a,Cow b){return a.r<b.r;}
}cows[25005];
int main()
{
    int n,t,i;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;++i)scanf("%d%d",&cows[i].l,&cows[i].r);
    sort(cows,cows+n);
    bool flag;
    int count=0,curindex=-1,curr=0;
    while(curr<t){
        flag = false;
        for(i=n-1;i>curindex;--i){
            if(cows[i].l<=curr+1){
                curr = cows[i].r;
                count++;
                curindex = i;
                flag = true;
                break;
            }
        }
        if(!flag){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n",count);
    return 0;
}