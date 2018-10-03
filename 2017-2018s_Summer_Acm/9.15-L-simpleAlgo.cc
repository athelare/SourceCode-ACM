#include<iostream>
const long long mod = 1000000007;
using namespace std;
int main()
{
    long long n,aa,ab,ac,ba,bb,bc,ca,cb,cc,
                taa,tab,tac,tba,tbb,tbc,tca,tcb,tcc;
    for(int i=1;i<=100;++i){
        n=i;
        if(n == 1 || n == 2){
            cout<<i<<' '<<(n==1?3:9)<<endl;
        }else{
            aa=ab=ac=ba=bb=bc=ca=cb=cc=1;
            while(n-- >2){
                taa = tbb = (ab+ca) %mod;
                tab = tba = (aa+ab+ca) %mod;
                tac = tbc = (aa+ab) %mod;
                tca = tcb = (ac+cc) %mod;
                tcc = (2*ac) %mod;
                aa=taa;bb=tbb;cc=tcc;ab=tab;ac=tac;ba=tba;bc=tbc;ca=tca;cb=tcb;
                //cout<<aa<<' '<<ab<<' '<<ac<<' '<<ca<<' '<<cc<<endl;
            }
            cout<<i<<' '<<((aa+bb+cc+ab+ac+bc+ba+ca+cb) %mod)<<endl;
        }
    }
    return 0;
}