#include<cstdio>
class Test{
    const int N,**A;
public:
    Test(int n):N(n){
        static int x[n][n];
    }
    void test(int x){
        int A[x];
    }
    ~Test(){delete[] A;}
    void input(){
        for(int i=0;i<N;++i){scanf("%d",&A[i]);}
    }
    void output(){
        for(int i=0;i<N;++i){

        }
    }
}