#include<iostream>
#include<cstdio>
using namespace std;
int Glades[2][300005];
int Mr,Mc,MaxS=0,ct;
long long result;
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2;++i)
    for(int j=0;j<n;++j){
        scanf("%d",&Glades[i][j]);
        if(Glades[i][j]>MaxS&&(i+j)){
            MaxS = Glades[i][j];
            Mr = i;Mc = j;
        }
    }
    result = 0;
    int r=0,c=0;
    int t = 0;
    if((Mc+Mr)%2 == 0){
        while(c<Mc-1){
            result+=Glades[r][c]*ct++;
            result+=Glades[1-r][c]*ct++;
            r=1-r;
            ++c;
        }
        for(int j=c;j<n;++j)result+=Glades[r][j]*ct++;
        r = 1-r;
        for(int j=n-1;j>=c;--j)result+=Glades[r][j]*ct++;
        printf("%lld\n",result);
    }else{
        while(c<Mc){
            result+=Glades[r][c]*ct++;
            result+=Glades[1-r][c]*ct++;
            r=1-r;
            ++c;
        }
        for(int j=c;j<n;++j)result+=Glades[r][j]*ct++;
        r = 1-r;
        for(int j=n-1;j>=c;--j)result+=Glades[r][j]*ct++;
        printf("%lld\n",result);
        
    }
    return 0;
}