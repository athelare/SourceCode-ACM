#include<iostream>
using namespace std;
long long a[10000];
int main(){
    a[0] = 0;
    a[1] = 2;
    for(int i=2;i<1000;++i){
        a[i] = i+1+(3*a[i-1]-a[i-2])/2;
        cout<<a[i]<<endl;
    }
    return 0;
}