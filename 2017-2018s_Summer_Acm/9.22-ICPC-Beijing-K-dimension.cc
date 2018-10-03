#include<iostream>
#include<cstdio>
using namespace std;
int K, X[105], C[105],our[105],T,sumX,n,r;
double res[105];
double solve(int t){
    int Para = 2 * t - sumX;
    return r + ((double)r + Para) / 2;
}
int main()
{
    cin >> T;
    while(T--){
        cin >> n >> K>>r;
        for (int i = 0; i < K;++i)
            cin >> C[i];
        while(n--){
            sumX = 0;
            for (int i = 0; i < K;++i){
                cin >> our[i];
                our[i] -= C[i];
                sumX += our[i];
            }
            for (int i = 0; i < K;++i){
                printf("%.6f%c", solve(our[i]), i == K - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
