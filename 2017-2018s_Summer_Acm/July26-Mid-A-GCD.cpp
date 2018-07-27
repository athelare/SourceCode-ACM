#include<cstdio>
long long gcd(long long a,long long b){
    return b?gcd(b,a%b):a;
}
int main(){
    long long a,b;
    while(~scanf("%lld%lld",&a,&b)){
        printf("%lld %lld\n",gcd(a,b),a*b/gcd(a,b));
    }
    return 0;
}