#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int n,d;
struct Period{
    double l,r;
    Period(){}
    Period(double x,double y){
        l = x-sqrt((double)d*d-y*y);
        r = x+sqrt((double)d*d-y*y);
    }
    friend bool operator<(Period a,Period b){return a.l<b.l;}
};
Period islands[1005];
int solve()
{
    int x,y,cur;
    double left;
    bool flag = true;
    for(int i=0;i<n;++i){
        scanf("%d%d",&x,&y);
        if(abs(y)>d)flag = false;
        islands[i] = Period(x,y);
    }
    if(!flag){
        printf("-1\n");
        return 0;
    }
    sort(islands,islands+n);
    int count=0;
    vector<double>right;
    for(int i=0;i<n;++i){
        right.push_back(islands[i].r);
        for(int j=0;j<right.size();++j){
            if(right[j]<islands[i].l){
                i--;
                count++;
                right.clear();
            }
        }
    }
    printf("%d\n",count+1);

    return 0;
}
int main()
{
    int t=1;
    while(cin>>n>>d){
        if(n==d && d == 0)break;
        printf("Case %d: ",t++);
        solve();
    }
    return 0;
}