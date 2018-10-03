#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    long long a,b,p,q,x,y,k;
    while(t--){
        cin>>a>>b>>p>>q;
        if(p == q && a < b){
            cout<<"-1\n";
            continue;
        }else if( p == 0){
            if( a == 0 )cout<<"0\n";
            else cout<<"-1\n";
            continue;
        }

        k = ceil((double)a/p);
        x = k*p - a;
        while(k<(double)(x+b)/q){
            k = (long long)(double)(x+b)/q+1;
            x = k*p - a;
        }
        y = k*q -b -x;
        cout <<x+y<<endl;
    }
    return 0;
}