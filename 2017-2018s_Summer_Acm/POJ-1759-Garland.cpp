#include<iostream>
#include<cstdio>
using namespace std;
bool judge(int N,double A,double se){
    double ls1=se,ls2=A,current;
    for(int i=2;i<N;++i){
        current = 2*(ls1+1)-ls2;
        if(current<0)return false;
        ls2=ls1;
        ls1=current;
    }
    return true;
}
int main()
{
    //std::ios::sync_with_stdio(false);
    int N;
    double A,l,r,m,B;
    //l,r:second lamp.
    while(cin>>N>>A){
        l=0,r=A,m=(l+r)/2;
        while(r-l>1e-6){
            if(judge(N,A,m))r=m;
            else l=m;
            m=(l+r)/2;
        }
        double ls1=r,ls2=A,current;
        for(int i=2;i<N;++i){
            current = 2*(ls1+1)-ls2;
            ls2=ls1;
            ls1=current;
        }
        printf("%.2f\n",current);
    }
    return 0;
}