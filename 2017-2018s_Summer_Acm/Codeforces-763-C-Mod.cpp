#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
#define MAXN 100005
long long Mod,N;
long long nums[MAXN];
set<int>numsAppear;
int main()
{
    cin>>N;
    for(int i=0;i<N;++i){
        scanf("%d",&nums[i]);
        numsAppear.insert(nums[i]);
    }
    for(int i=0;i<N;++i)
}