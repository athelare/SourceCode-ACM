//AC

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXV 5005
using namespace std;
int V;
long long cost[MAXV][MAXV];
long long  x[MAXV],a[MAXV],b[MAXV],c[MAXV],d[MAXV];

long long  inscost(long long i1,long long i2,long long mid){
    return  cost[i1][mid]+cost[mid][i2]-cost[i1][i2];
}
int main()
{
    int s,t,i,j;
    scanf("%d%d%d",&V,&s,&t);

    for(i=0;i<V;++i)scanf("%lld",&x[i]);
    for(i=0;i<V;++i)scanf("%lld",&a[i]);
    for(i=0;i<V;++i)scanf("%lld",&b[i]);
    for(i=0;i<V;++i)scanf("%lld",&c[i]);
    for(i=0;i<V;++i)scanf("%lld",&d[i]);

    for(i=0;i<V;++i)for(j=0;j<V;++j){
        if(i==j)continue;
        if(j<i){
            cost[i][j] = x[i] - x[j] + c[i] + b[j];
        }else{
            cost[i][j] = x[j] - x[i] + d[i] + a[j];
        }
    }
    //for(i=0;i<V;++i)for(j=0;j<V;++j)printf("%lld%c",cost[i][j],j==V-1?'\n':' ');
    s--,t--;
    long long minv;
    int mini;
    vector<int>sequ;
    sequ.push_back(s);sequ.push_back(t);
    for(int i=0;i<V;++i){
        if(i==s||i==t)continue;
        minv = inscost(sequ[0],sequ[1],i);mini = 1;
        for(size_t j = 2;j<sequ.size();++j){
            long long tmpcos = inscost(sequ[j-1],sequ[j],i);
            if(tmpcos<minv){
                minv = tmpcos;
                mini = j;
            }
        }
        sequ.insert(sequ.begin()+mini,i);
        //for(int i=0;i<sequ.size();++i)printf("%d%c",sequ[i],i==sequ.size()-1?'\n':' ');
    }
    long long ans=0;
    for(int i=0;i<V-1;++i)ans+=cost[sequ[i]][sequ[i+1]];
    printf("%lld\n",ans);
    return 0;
}
