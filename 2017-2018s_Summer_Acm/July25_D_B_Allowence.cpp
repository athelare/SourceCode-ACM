#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>

using namespace std;
#define Coin pair<int,int>
#define value first
#define quantity second
Coin coins[25];
bool operator<(Coin a,Coin b){
    return a.value<b.value;
}

int main()
{
    int n,c,wks=0;
    cin>>n>>c;
    for(int i=0;i<n;++i){
        cin>>coins[i].value>>coins[i].quantity;
    }
    sort(coins,coins+n);
    while(coins[n-1].value>=c){
        wks+=coins[n-1].quantity;
        n--;
    }
    int need = c;
    while(1){
        for(int i=n-1;i>=0;--i){
            if(need>0 && coins[i].quantity>0){
                int t = min(coins[i].quantity,need/coins[i].value);
                need -= t*coins[i].value;
                coins[i].quantity-=t;
            }
        }
        for(int i=0;i<n;++i){
            if(need>0 && coins[i].quantity>0){
                int t = min(coins[i].quantity,(int)ceil((double)need/(double)coins[i].value));
                need -= t*coins[i].value;
                coins[i].quantity-=t;
            }
        }
        if(need>0)break;
        wks++;
        need = c;
    }
    printf("%d\n",wks);
    return 0;
}

