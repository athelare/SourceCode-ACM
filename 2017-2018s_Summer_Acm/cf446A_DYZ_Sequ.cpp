#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
#define P pair<int ,int >
int n;
void solve()
{
    vector<long long>a(n+5);
    for(int i=0;i<n;++i)scanf("%lld",&a[i]);

    vector<P>upSeg;
    upSeg.push_back(make_pair(0,0));

    for(int i=1;i<n;++i){
        if(a[i]<=a[i-1]){
            upSeg.back().second = i-1;
            upSeg.push_back(make_pair(i,0));
        }
    }
    upSeg.back().second=n-1;

    int mxlen =upSeg[0].second - upSeg[0].first ;
    for(int i=0;i<upSeg.size()-1;++i){
        mxlen = max(mxlen,upSeg[i+1].second - upSeg[i+1].first);
        if( upSeg[i].second - upSeg[i].first == 0&&
            upSeg[i+1].second - upSeg[i+1].first == 0){
                continue;
        }else if(upSeg[i].second - upSeg[i].first == 0||
            upSeg[i+1].second - upSeg[i+1].first == 0){
                mxlen = max(mxlen,max(upSeg[i].second - upSeg[i].first,upSeg[i+1].second - upSeg[i+1].first));

        }
        if( a[upSeg[i].second]+1<a[upSeg[i+1].first+1]||
            a[upSeg[i].second-1]+1<a[upSeg[i+1].first]){
                if(upSeg[i].second-upSeg[i].first+upSeg[i+1].second-upSeg[i+1].first > mxlen){
                    mxlen = upSeg[i].second-upSeg[i].first+upSeg[i+1].second-upSeg[i+1].first;
                }
            }
    }
    printf("%d\n", n == 1?1:mxlen+1+(upSeg.size()>1));
}
int main()
{
    while(cin>>n)solve();
    return 0;
}