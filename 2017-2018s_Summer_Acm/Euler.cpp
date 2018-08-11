#include<iostream>
using namespace std;
int euler(int n){
    int r=n,a=n;
    for(int i=2;i*i<=a;++i){
        if(a%i == 0){
            r = r/i*(i-1);
            while(a%i == 0)a/=i;
        }
    }
    if(a>1)r = r/a*(a-1);
    return r;
}
int main(){
    int n;
    while(cin>>n&&n)cout<<euler(n)<<endl;
    return 0;
}