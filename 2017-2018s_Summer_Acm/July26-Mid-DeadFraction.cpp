#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long

void solve();
ll ppow(int n){
    ll num = 1;
    while(n--)num*=10;
    return num;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b) : a;
}
void solve()
{
    

}