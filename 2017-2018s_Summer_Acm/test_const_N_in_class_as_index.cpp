#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int> > A(18);
class Test{
    vector<vector<int>> A;
public:
    Test(int n):A(n){
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