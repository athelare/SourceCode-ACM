#include<cstdio>
#include<iostream>
#define ll long long
#define mod 1000000007
using namespace std;
class Matrix{
    public:
    ll ma[2][2];
    Matrix(){
        ma[0][0] = ma[1][1] = ma[0][1] = ma[1][0] = 0;
    }
    Matrix(int a11, int a12, int a21, int a22) {
        ma[0][0] = a11, ma[0][1] = a12, ma[1][0] = a21, ma[1][1] = a22;
    }
    friend Matrix operator * (const Matrix &a,const Matrix &b){
        Matrix c;
        int i, j, k;
        for (i = 0; i < 2;++i){
            for (j = 0; j < 2;++j){
                for (k = 0; k < 2;++k){
                    c.ma[i][j] = (c.ma[i][j] + a.ma[i][k] * b.ma[k][j]) % mod;
                }
            }
        }
        return c;
    }
    friend Matrix operator^(Matrix base,long long ppow){
        Matrix ans(1, 0, 0, 1);
        while (ppow > 0)
        {
            if(ppow&1)
                ans = ans * base;
            base = base * base;
            ppow >>= 1;
        }
        return ans;
    }
};
int main()
{
    long long A, B, n, x;
    while(cin >> A >> B >> n >> x){
        Matrix base = Matrix(A, B, 0, 1) ^ n;
        printf("%lld\n", (base.ma[0][0] * x + base.ma[0][1]) % mod);
    }
    return 0;
}