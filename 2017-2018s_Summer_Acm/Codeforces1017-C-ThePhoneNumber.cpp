#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int g = (int)sqrt(n);
    int m = n/g + (n%g!=0);
    int di = n%g == 0?0:m-n%m;
    g--;
    while(g >=0){
        for(int i=0;i<m;++i){
            if(g*m+i+1-di>0)
                cout<<g*m+i+1-di<<' ';
        }
        g--;
    }
    cout<<endl;
    return 0;
}