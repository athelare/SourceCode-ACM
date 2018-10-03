#include<iostream>
#include<cstdio>
#include<set>
#include<map>
using namespace std;
typedef pair<int,int> P;
P waves[50005];
int N;
int main()
{
    int i,j,l,r;
    scanf("%d",&N);
    set<int>hori;
    set<int>::iterator lbit;
    map<int,int>index;
    long long sum=0;
    for(i=N-1;i>=0;--i){
        scanf("%d%d",&waves[i].first,&waves[i].second);
    }
    for(i=0;i<N;++i ){
        index[waves[i].first]=i;
        if(hori.empty()){
            sum+=waves[i].first+waves[i].second;
        }else{
            lbit = hori.lower_bound(waves[i].first);
            if(lbit == hori.end()){
                l = index[*--lbit];
                sum+=waves[i].first - waves[l].first;
                sum+=waves[i].second;
            }else if(lbit == hori.begin()){
                r = index[*lbit];
                sum+=waves[i].first;
                sum+=waves[i].second - waves[r].second;
            }else{
                r = index[*lbit];
                l = index[*--lbit];
                sum+=waves[i].first - waves[l].first;
                sum+=waves[i].second - waves[r].second;
            }
        }
        hori.insert(waves[i].first);
    }

    cout<<sum<<endl;
    return 0;
}