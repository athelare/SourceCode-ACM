#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    unsigned long long N,L,D,S,ans;
    int few[] ={1,9,41,109,205};
    int T,t=0;
    scanf("%d",&T);
    while(t++<T){
        cin>>N;
        if(N<=3){
            ans = few[N];
        }else{
            L = 2*N +1;
            D = N -1;
            ans = (12*N+(L+2*D-2)*(L+2*D-2) - 2*(D)*(D-1));
        }
        

        cout<<"Case #"<<t<<": "<<  ans <<endl;;
    }
    return 0;
}
                    
 