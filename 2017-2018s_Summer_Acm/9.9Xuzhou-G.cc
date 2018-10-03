#include<iostream>
#include<cstdio>
using namespace std;
typedef pair<int,int> P;
P verti[50005],hori[50005];
int N;
int main()
{
    int i,j;
    long long sum;
    fill(verti,verti+50005,make_pair(0,0));
    fill(hori,hori+50005,make_pair(0,0));
    scanf("%d",&N);
    for(i=0;i<N;++i){
        scanf("%d%d",&hori[i].second,&verti[i].second);
        for(j=0;j<i;++j){
            if(	hori[i].second > hori[j].second &&
            	verti[i].second > verti[j].first){
                verti[j].first = verti[i].second;
            }else{
                if(hori[i].second > hori[j].first)
                hori[j].first = hori[i].second;
            }
        }
    }
    sum=0;
    for(i=0;i<N;++i){
        sum+=(hori[i].second - hori[i].first);
        sum+=(verti[i].second - verti[i].first);
    }
    printf("%lld\n",sum);
    return 0;
}