#include<iostream>
#include<cstdio>
using namespace std;
char a[100005],b[100005];
int n;
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    cin>>a>>b;
    int zz=0,zo=0,oz=0,oo=0;
    for(int i=0;i<n;++i){
        if(a[i] == '1' && b[i] == '1')oo++;
        else if(a[i] == '0' && b[i] == '0')zz++;
        else if(a[i] == '0' && b[i] == '1')zo++;
        else if(a[i] == '1' && b[i] == '0')oz++;
    }
    long long ans = (long long)oo*zz+(long long)(zo+zz)*(oz);
    cout<<ans<<endl;
    return 0;
}