#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5+10;
typedef long long ll;
#define rep(i,s,n)  for(ll i=s;i<=n;i++)
#define per(i,n,s)  for(ll i=n;i>=s;i--)
struct node{
    ll x,y;
}p[Max];
ll gcd(ll a, ll b){
    return b==0 ? a : gcd (b,a%b);
}//皮克定理:多边形的面积 = 多边形内部整点的个数 + 边上正点的个数 / 2 - 1；
int main(){
    int n;
    scanf("%d",&n);
    rep(i,0,n-1){
            scanf("%I64d %I64d",&p[i].x,&p[i].y);
    }
    ll sum=0;
    rep(i,0,n-1){
            sum+=(p[(i+1)%n].y)*(p[i].x-p[(i+2)%n].x);
    }//这是在求多边形的面积；
    ll edg=0;
    rep(i,0,n-1){
        edg+=gcd(abs(p[i].x-p[(i+1)%n].x),abs(p[i].y-p[(i+1)%n].y));
    }//这是在求边界上面的点
    sum=abs(sum);
    sum=(sum-edg)/2+1;
    //求多边形里面的点
    printf("%I64d\n",sum);
    return 0;
}