#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


typedef pair<long long,long long > P;
double x;
bool cmp(P a,P b){return a.first - x*a.second < b.first - x*b.second;}
P scores[1005];
int main()
{
    int n,k;
    long long a,b;
    while(cin>>n>>k){
        if(n+k == 0)break;
        for(int i=0;i<n;++i)cin>>scores[i].first;
        for(int i=0;i<n;++i)cin>>scores[i].second;
        double l=0,r=1,mid = (l+r)/2;
        while(r-l>1e-7){
            vector<P>list(scores,scores+n);
            x=mid;
            sort(list.begin(),list.end(),cmp);
            long long up=0,down=0;
            for(int i=k;i<n;++i){
                up+=list[i].first;
                down += list[i].second;
            }
            if((double)up/down > mid){
                l=mid;
            }else{
                r=mid;
            }
            mid = (l+r)/2;
        }
        cout<<round(100.0*mid)<<endl;
    }
    return 0;
}