#include<cstdio>
#include<algorithm>
#include<iostream>
#include<list>
using namespace std;
struct Cow{
    bool ok;
    int l,r,s,in;
    Cow(){}
    friend bool operator<(Cow a,Cow b){return a.l<b.l;}
}cows[50002];
bool cmp(Cow a,Cow b){
    return a.in<b.in;
}
bool operator <(Cow a,int b){
    return a.l<b;
}
//list<pair<int,int>>cowlist;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d%d",&cows[i].l,&cows[i].r);
        cows[i].in = i;
    }
    sort(cows,cows+n);
    int count=0,r;
    bool flag = true;
    while(flag){
        flag = false;
        count ++;
        r=0;
        for(int i=0;i<n;++i){
            if(!cows[i].ok && cows[i].l>r){
                cows[i].s = count;
                r= cows[i].r;
                cows[i].ok = true;
                flag = true;
                i = lower_bound(cows,cows+n,r+1) - cows;
            }
        }
    }
    sort(cows,cows+n,cmp);
    printf("%d\n",count-1);
    for(int i=0;i<n;++i)printf("%d\n",cows[i].s);
    return 0;
}