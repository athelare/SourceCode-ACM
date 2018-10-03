#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <vector>
#include <time.h>
#define ll long long

#define INF 0x3f3f3f3f
#define maxn 10000+10
#define cle(a) memset(a,0,sizeof(a))
const double eps=1e-5;
const long long mod = 1000000007;
using namespace std;

const int S=20;//随机算法判定次数，S越大，判错概率越小
//计算 (a*b)%c.   a,b都是long long的数，直接相乘可能溢出的
//  a,b,c <2^63
ll mult_mod(ll a,ll b,ll c)
{
    a%=c;
    b%=c;
    ll ret=0;
    while(b)
    {
        if(b&1){ret+=a;ret%=c;}
        a<<=1;
        if(a>=c)a%=c;
        b>>=1;
    }
    return ret;
}
ll pow_mod(ll x,ll n,ll mod)
{
    if(n==1)return x%mod;
    x%=mod;
    ll tmp=x;
    ll ret=1;
    while(n)
    {
        if(n&1) ret=mult_mod(ret,tmp,mod);
        tmp=mult_mod(tmp,tmp,mod);
        n>>=1;
    }
    return ret;
}
//以a为基,n-1=x*2^t      a^(n-1)=1(mod n)  验证n是不是合数
//一定是合数返回true,不一定返回false
bool check(ll a,ll n,ll x,ll t)
{
    ll ret=pow_mod(a,x,n);
    ll last=ret;
    for(int i=1;i<=t;i++)
    {
        ret=mult_mod(ret,ret,n);
        if(ret==1&&last!=1&&last!=n-1) return true;//合数
        last=ret;
    }
    if(ret!=1) return true;
    return false;
}
// Miller_Rabin()算法素数判定
//是素数返回true.(可能是伪素数，但概率极小)
//合数返回false;
bool Miller_Rabin(ll n)
{
    if(n<2)return false;
    if(n==2)return true;
    if((n&1)==0) return false;//偶数
    ll x=n-1;
    ll t=0;
    while((x&1)==0){x>>=1;t++;}
    for(int i=0;i<S;i++)
    {
        ll a=rand()%(n-1)+1;//rand()需要stdlib.h头文件
        if(check(a,n,x,t))
            return false;//合数
    }
    return true;
}
ll factor[100];//质因数分解结果（刚返回时是无序的）
int tol;//质因数的个数。数组小标从0开始
ll gcd(ll a,ll b)
{
    if(a==0)return 1;//???????
    if(a<0) return gcd(-a,b);
    while(b)
    {
        ll t=a%b;
        a=b;
        b=t;
    }
    return a;
}
ll Pollard_rho(ll x,ll c)
{
    ll i=1,k=2;
    ll x0=rand()%x;
    ll y=x0;
    while(1)
    {
        i++;
        x0=(mult_mod(x0,x0,x)+c)%x;
        ll d=gcd(y-x0,x);
        if(d!=1&&d!=x) return d;
        if(y==x0) return x;
        if(i==k){y=x0;k+=k;}
    }
}
//对n进行素因子分解
void findfac(ll n)
{
    if(Miller_Rabin(n))//素数
    {
        factor[tol++]=n;
        return;
    }
    ll p=n;
    while(p>=n)p=Pollard_rho(p,rand()%(n-1)+1);
    findfac(p);
    findfac(n/p);
}
long long getsum(long long fac,long long max){
    long long n = max/fac;
    long long res;
    res = n*(n+1)/2;
    res%=mod;
    res=(fac*fac*res*(2*n+1)/3)%mod;
    res=(res+fac*(n+1)*n/2)%mod;
    return res;
}
int main()
{
    ll n,m,sumn,sumcm,sumf;
    set<long long>factors_tmp;
    vector<long long>factors;
    vector<long long>commom_multi;
    while(cin>>n>>m){
        tol=0;
        if(m == 1){
            cout<<getsum(1,n)<<endl;
            continue;
        }
        findfac(m);
        for(int i=0;i<tol;i++)factors_tmp.insert(factor[i]);
        for(set<long long>::iterator it = factors_tmp.begin();it != factors_tmp.end();++it)factors.push_back(*it);
        //质因子存放在vector：factors中
        int len = factors.size();
        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                commom_multi.push_back(factors[i]*factors[j]);
            }
        }
        sumf=sumn=sumcm=0;
        sumn = getsum(1,n);
        for(int i=0;i<factors.size();++i)sumf=(sumf+getsum(factors[i],n))%mod;
        for(int i=0;i<commom_multi.size();++i)sumcm=(sumcm+getsum(commom_multi[i],n))%mod;
        long long ans = -sumf;
        ans+=(sumn%mod+sumcm%mod)%mod;
        ans = (ans+mod)%mod;
        cout<<ans<<endl;
        factors_tmp.clear();
        commom_multi.clear();
        factors.clear();
    }
    return 0;
}