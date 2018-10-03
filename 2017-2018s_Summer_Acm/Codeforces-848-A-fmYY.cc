#include<iostream>
#include<cstdio>
using namespace std;
int SumTable[505];
int main()
{
    for(int i=0;i<=500;++i)SumTable[i] = (i-1)*i/2;
    int n,lft,start = 500,div;
    cin>>n;
    char curl = 'a';
    if(n == 0)printf("a");
    while(n>0){
        while(n<SumTable[start])start--;
        n-=SumTable[start];
        for(int i=0;i<start;++i)putchar(curl);
        curl++;
    }
    printf("\n");
    return 0;
}
