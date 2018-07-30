#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;


typedef pair<int,pair<int,int> > P;
#define index first
#define value second.first
#define weight second.second

double x;
bool cmp(P a,P b){return a.value - x*a.weight > b.value - x*b.weight;}
P scores[100001];
int main()
{
    int n,k;

    while(cin>>n>>k){
        for(int i=0;i<n;++i){
            cin>>scores[i].value>>scores[i].weight;
            scores[i].index = i;
        }
        double l=0,r=1e50,mid = (l+r)/2;
        while(r-l>1e-6){
            vector<P>list(scores,scores+n);
            x=mid;
            sort(list.begin(),list.end(),cmp);

            double up=0,down=0;
            for(int i=0;i<k;++i){
                up+=list[i].value;
                down += list[i].weight;
            }
            if((double)up/down > mid){
                l=mid;
            }else{
                r=mid;
            }
            mid = (l+r)/2;
        }
        vector<P>list(scores,scores+n);
        sort(list.begin(),list.end(),cmp);
        for(int i=0;i<k;++i){printf("%d%c",1+scores[i].index,i==k-1?'\n':' ');}
    }
    return 0;
}

