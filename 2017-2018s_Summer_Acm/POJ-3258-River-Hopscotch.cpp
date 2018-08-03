#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 50005
int N,M,L;
long long dis[MAXN]={0};
bool ok(long long mxdis){
    int count=0,before = 0;
    for(int i =1;i<=N+1;){
        if(dis[i] - dis[before]>=mxdis){
            ++i;
            before = i-1;
        }else{
            ++i;++count;
        }
    }
    return count<=M;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>L>>N>>M){
        for(int i=1;i<=N;++i)cin>>dis[i];
        dis[N+1]=L;
        sort(dis,dis+N+1);
        long long l=0,r=2*L,m = (l+r)>>1;
        while(l<r-1){
            if(ok(m)){
                l=m;
            }else{
                r=m;
            }
            m = (l+r)>>1;
        }
        cout<<l<<endl;
    }
    return 0;
}