#include<iostream>
#include<cstdio>
using namespace std;
bool judgePrime(int n){
    for(int i=2;i<n;++i)if(n%i==0)return false;
    return true;
}
int getn(int a[],int l,int r){
    int ans=0;
    for(;l<=r;++l){
        ans*=10;
        ans+=a[l];
    }
    return ans;
}
bool judgeNumber(int n){
    int a[6];
    if(n<10){
        return judgePrime(n);
    }else if(n<100){
        return judgePrime(n/10) && judgePrime(n%10) && judgePrime(n);
    }else if(n<1000){
        a[0] = n/100;
        a[1] = (n%100)/10;
        a[2] = n%10;
        for(int i=0;i<=2;++i){
            for(int j=0;j<=2;++j){
                if(!judgePrime(getn(a,i,j)))return false;
            }
        }
        return true;
    }else if(n<10000){
        a[0] = n/1000;
        a[1] = (n%1000)/100;
        a[2] = (n%100)/10;
        a[3] = n%10;
        for(int i=0;i<=3;++i){
            for(int j=0;j<=3;++j){
                if(!judgePrime(getn(a,i,j)))return false;
            }
        }
        return true;
    }
}
int main()
{
    for(int i=1;i<10000;++i){
        if(judgeNumber(i)){
            cout<<i<<',';
        }
    }
    cout<<endl;
    return 0;
}