#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,h,a,b,k;
    int t1,t2,h1,h2;
    cin>>n>>h>>a>>b>>k;
    while(k--){
        cin>>t1>>h1>>t2>>h2;
        if(t1 == t2){
            cout<<abs(h1-h2)<<endl;
        }else if(h1>b && h2 > b){
            cout<<abs(t1-t2)+abs(h2-b)+h1-b<<endl;
        }else if(h2 < a && h1 < a){
            cout<<abs(t1-t2)+abs(h2-a)+a-h1<<endl;
        }else{
            cout<<abs(t1-t2)+abs(h1-h2)<<endl;
        }
    }
    return 0;
}