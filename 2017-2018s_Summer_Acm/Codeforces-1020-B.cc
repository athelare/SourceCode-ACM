#include<iostream>
using namespace std;
int h[1004];
int p[1004];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)cin>>p[i];
    for(int i=1;i<=n;++i){
        fill(h+1,h+n+1,0);
        h[i]++;
        for(int j=p[i];;j = p[j]){
            if(h[j]){cout<<j<<endl;
            break;}
            h[j]++;
        }
    }
    return 0;
}