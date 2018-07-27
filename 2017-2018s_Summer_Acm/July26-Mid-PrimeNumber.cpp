#include<cstdio>
using namespace std;
bool primeList[1000000];
int primebf[1000000];
int main()
{
    primeList[1]=
    primeList[4]=
    primeList[6]=
    primeList[8]=
    primeList[9]=true;
    for(int i=2;i<10;++i){
        if(!primeList[i]){
            for(int j=2;i*j<100;++j){
                primeList[j*i]=true;
            }
        }
    }
    for(int i=2;i<60;++i){
        if(!primeList[i]){
            for(int j=2;i*j<=1000;++j){
                primeList[j*i]=true;
            }
        }
    }
    for(int i=2;i<=1000;++i){
        if(!primeList[i]){
            for(int j=2;i*j<1000000;++j){
                primeList[j*i]=true;
            }
        }
    }
    int count=0;
    for(int i=1;i<1000000;++i){
        if(!primeList[i])count++;
        primebf[i]=count;
    }
    int n;
    while(~scanf("%d",&n))printf("%d\n",primebf[n]);
    return 0;
}