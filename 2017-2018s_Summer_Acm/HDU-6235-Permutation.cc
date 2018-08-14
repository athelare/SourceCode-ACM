#include<iostream>
#include<cmath>
using namespace std;
void solve(int n){
    int halfn=n/2;
    if(n%2){
        for(int i=1;i<=halfn;++i){
            cout<<i<<' '<<i+halfn+1<<' ';
        }
        cout<<halfn+1<<endl;
    }else{
        for(int i=1;i<=halfn;++i){
            cout<<i<<' '<<i+halfn<<(i == halfn?'\n':' ');
        }
    }
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        solve(n);
    }
}