#include<iostream>
#include<cmath>
using namespace std;
void Stern_Brocot_tree(long long k){
    long long lu=0,ld=1,mu=1,md=1,ru=1,rd=0,ansu,ansd;
    while(md<100000-1){
        if(mu*mu*mu == k*k*md*md*md){
            cout<<mu<<'/'<<md<<endl;
            return;
        }
        ansu = mu,ansd = md;
        if(mu*mu*mu > k*k*md*md*md){
            ru=mu;
            rd=md;
        }else{
            lu=mu;
            ld=md;
        }
        mu = lu+ru;
        md = ld+rd;
    }
    cout<<ansu<<'/'<<ansd<<endl;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        Stern_Brocot_tree(n);
    }
    return 0;
}