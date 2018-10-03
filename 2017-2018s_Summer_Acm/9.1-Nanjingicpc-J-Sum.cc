#include<iostream>
#include<cstdio>
using namespace std;
void solve(int n){
    int count=0;
    for(int i=n;i<=n;++i){
        for(int j=1;j<=i;++j){
            if(i%j == 0){
                bool flag=true;
                int a = j,b = i/j;

                for(int m=2;m*m<=a;++m){
                    if(a%(m*m)==0)flag = false;
                }
                for(int m=2;m*m<=b;++m){
                    if(b%(m*m)==0)flag = false;
                }
                if(flag)count++;
            }
            
        }
    }
    cout<<count<<endl;
}
int main()
{
    for(int i=1;i<=1000;++i){
        cout<<i<<' ';
        solve(i);
    }
    cout<<"Hello"<<endl;
    return 0;
}