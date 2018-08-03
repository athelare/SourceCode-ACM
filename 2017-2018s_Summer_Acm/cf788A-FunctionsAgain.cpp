#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
int n;
long long maxSum(){
    long long b=0,sum=0,sum2=0;
    for(int i=1;i<n;++i){
        if(b>0){
            b+=a[i];
        }else{
            b=a[i];
        }
        if(b>sum)sum=b;
    }
    b=0;
    for(int i=1;i<n;++i){
        if(b<0){
            b+=a[i];
        }else{
            b=a[i];
        }
        if(b<sum2)sum2=b;
    }
    sum2*=-1;
    return max(sum,sum2);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=n-2;i>=0;--i)a[i+1]-=a[i];
    for(int i=1;i<n;i++){
        if(i%2)a[i] = abs(a[i]);
        else a[i] =-abs(a[i]);
    }
    cout<<maxSum()<<endl;
    return 0;
}