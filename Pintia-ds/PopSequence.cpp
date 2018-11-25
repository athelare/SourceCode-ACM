#include<iostream>
#define MXN 1005
#define INIT \
    sp = 0;  \
    k = 1;
#define POP --sp
#define TOP Stack[sp - 1]
#define PUSH Stack[sp++] = k++;
using namespace std;
int main()
{
    int Stack[MXN], Sequ[MXN], M, N, K,i,j,k,sp;
    cin >> M >> N >> K;
    while(K--){
        for (i = 0; i < N;++i)
            cin >> Sequ[i];
        INIT;
        for (i = 0; i < N;++i){
            while(sp == 0 || TOP < Sequ[i])
                PUSH;
            if(TOP != Sequ[i] || sp>M){
                cout << "NO" << endl;
                break;
            }
            POP;
        }
        if(i==N)cout << "YES" << endl;
    }
    return 0;
}