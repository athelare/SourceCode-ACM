#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long a,b,p,q,x,y,k,l,r,m;
    while(t--){
        cin>>a>>b>>p>>q;
        if(p == q && a < b){
            cout<<"-1\n";
            continue;
        }else if( p == 0){
            if( a == 0 )cout<<"0\n";
            else cout<<"-1\n";
            continue;
        }else if(a*q == p*b){
            cout<<"0\n";
            continue;
        }
        l = 0,r=0x7fffffffffffffff;
        r/= q;
        r++;
        m = (l+r)>>1;
        while(r>l+1){
            if(a<=m*p && m*(q-p)>=b-a)r=m;
            else l=m;
            m = (l+r)>>1;
        }
        cout<<r*q-b<<endl;

    }
    return 0;
}