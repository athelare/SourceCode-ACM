#include<cstdio>
#include<iostream>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
    return a? gcd(b % a, a) : b;
}
int main()
{
    ll n, a, b, p, q, common_multiple,cmv, leave;
    while(cin>>n>>a>>b>>p>>q){
        common_multiple = a * b / gcd(a, b);
        cmv = p * (common_multiple / a) + q * (common_multiple / b) - ((p > q) ? q : p);
        leave = n % common_multiple;
        cout << (cmv * (n / common_multiple) + p * (leave / a) + q * (leave / b))<<endl;
    }
    return 0;
}