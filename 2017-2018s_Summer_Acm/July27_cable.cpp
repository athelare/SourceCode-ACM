#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    long long k,m;
    while(cin>>m>>k){
        cout<<k*(m-k+1)<<endl;
    }
    return 0;
}