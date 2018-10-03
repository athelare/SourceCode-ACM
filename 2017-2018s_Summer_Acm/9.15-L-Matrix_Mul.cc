#include<iostream>
#include<cstdio>
#include<cstring>
#define DIM 5
using namespace std;
const long long mod = 1000000007;
long long eye[][DIM] = {
            {1,0,0,0,0},
            {0,1,0,0,0},
            {0,0,1,0,0},
            {0,0,0,1,0},
            {0,0,0,0,1}
        };
class Matrix{
public:
    long long ma[DIM][DIM];
    Matrix(){
        memset(ma,0,sizeof(ma));
    }
    Matrix(long long inp[DIM][DIM]){
        for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j)ma[i][j] = inp[i][j];
    }
    Matrix(const Matrix & ori){
        for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j)ma[i][j] = ori.ma[i][j];
    }
    friend Matrix operator *(const Matrix &a,const Matrix &b){
        Matrix c;
        for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j)for(int k=0;k<DIM;++k){
            c.ma[i][j] = (c.ma[i][j] + a.ma[i][k]*b.ma[k][j])%mod;
        }
        return c;
    }
    friend Matrix operator ^ (const Matrix &b,long long pp){
        Matrix ans;
        for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j)ans.ma[i][j] = eye[i][j];
        Matrix base = b;
        while(pp>0){
            if(pp&1)
                ans = ans*base;
            base = base*base;
            pp>>=1;
        }
        return ans;
    }
};
int main()
{
    int T;
    long long ans,n,ori[] = {2,2,2,2,1};
    long long trans[DIM][DIM] = {
        {0,1,0,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,1,0,1},
        {0,0,2,0,0}
    };
    cin>>T;
    while(T--){
        cin>>n;
        if(n == 1 || n == 2){
            cout<<(n==1?3:9)<<endl;
        }else{
            Matrix m0;
            for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j)m0.ma[i][j] = trans[i][j];
            m0 = m0^(n-2);
            ans = 0;
            for(int i=0;i<DIM;++i)for(int j=0;j<DIM;++j){
                ans = (ans+ori[i]*m0.ma[i][j])%mod;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}