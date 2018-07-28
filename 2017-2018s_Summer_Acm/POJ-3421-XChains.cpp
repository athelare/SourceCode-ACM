#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

long long A[25] = {0,1};

int main()
{
    int n,i,all;
    for(int i=2;i<22;++i){
        A[i] = i*A[i-1];
    }

    while(~scanf("%d",&n)){
        vector<int>times;
        all=0;
        for(i=2;i*i<=n;++i){
            int time=0;
            if(n%i==0){
                while(n%i==0){
                    time++;
                    all++;
                    n/=i;
                }
                times.push_back(time);
            }
        }
        if(n!=1)all++;
        long long ans=A[all];
        for(vector<int>::iterator it = times.begin();it!=times.end();++it){
            ans/=A[*it];
        }
        printf("%d %lld\n",all,ans);
    }
    return 0;
}