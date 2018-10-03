#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
    char pare[] = "()";
    int T,w,h;
    cin>>T;
    while(T--){
        cin>>h>>w;
        /*if(h%2==0 && w%2 == 0){
            for(int i=0;i<h;++i,putchar('\n'))
            for(int j=0;j<w;++j)putchar(pare[(i+j)&1]);
        }
        else */if((w>=h && h%2==0)||w%2==1){
            for(int i=0;i<h;++i,putchar('\n'))
            for(int j=0;j<w;++j)putchar(pare[i&1]);
        }
        else{
            for(int i=0;i<h;++i,putchar('\n'))
            for(int j=0;j<w;++j)putchar(pare[j&1]);
        }
    }
    return 0;
}