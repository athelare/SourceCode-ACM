#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;

int main()
{
    int n,k,d=0;
    vector<int> drop;
    long long accumulate,ration,cur;
    while(cin>>n>>k){
        accumulate=d=0;
        scanf("%I64d",&ration);
        for(int i=2;i<=n;++i){
            scanf("%I64d",&ration);
            cur = accumulate - (n-i)*(i-d-1)*ration;
            if(cur<k){
                drop.push_back(i);
                d++;
            }else{
                accumulate+=ration*(i-d-1);
            }
        }
        for(int i=0;i<d;++i){
            printf("%d\n",drop[i]);
        }
            
    }
    return 0;
}