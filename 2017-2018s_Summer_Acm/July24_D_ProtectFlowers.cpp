#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef pair<int,int> Cow;
#define time first
#define eat second

bool cmp (const Cow& a, const Cow& b){
    return a.time*b.eat < b.time*a.eat;  
}
Cow cows[100003];
int n;

void solve(){
    long long destroys=0;
    long long time=0;
    sort(cows,cows+n,cmp);
    for(int i=0;i<n;++i){
        destroys+=cows[i].eat*time;
        time+=2*cows[i].time;
    }
    printf("%lld\n",destroys);
}
int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)
            scanf("%d%d",&cows[i].time,&cows[i].eat);
        solve();
    }
    return 0;
}
