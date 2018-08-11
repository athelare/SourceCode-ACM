#include<iostream>
#include<cstdio>
#include<string>
#include<set>
using namespace std;

int W[13], N;
char test[20];
multiset<string>strs;
bool tell(string b,int k){
    int Ans=0;
    for(int i=0;i<N;++i){
        if(test[i] == b[i])Ans+=W[i];
    }
    return Ans<=k;
}
int main()
{
    int m,q,k;
    string tmp;
    cin>>N>>m>>q;
    int mp = 1<<N;
    for(int i=0;i<N;++i)cin>>W[i];
    for(int i=0;i<m;++i){
        cin>>tmp;
        strs.insert(tmp);
    }
    for(int i=0;i<q;++i){
        cin>>tmp>>k;
        int res=0;
        for(int j=0;j<mp;++j){
            for(int k=0;k<N;++k){
                test[k] ='0'+ ((j & (1<<(k)))>0);
            }
            if(tell(tmp,k)){
                int pp = strs.count(test);
                res+=pp;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}