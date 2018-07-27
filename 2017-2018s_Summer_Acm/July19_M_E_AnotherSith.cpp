#include<iostream>
#include<cstdio>
#define eps 1e-6
using namespace std;

double WinRate[20][20];
int n;

int C(int a, int n)
{
    int ans = 1;
    while (++a<=n)
        ans *= a;
    return ans;
}
inline bool getBit(int num, int n) { return num & (1 << (n - 1));}
inline int setBitZero(int &num, int n) { return num ^= (1 << (n - 1)); }
inline void setBitOne(int &num, int n) { num |= (1 << (n - 1)); }
double dfsWin(int state,int cur,int left){
    double maxWinRate = 0,maxindex = -1;
    double Win = 0;
    for (int i = 1; i <= n; ++i)
    {
        if(getBit(state,i) && WinRate[cur][i]>maxWinRate){
            maxWinRate = WinRate[cur][i];
            maxindex = i;
        }
    }
    for (int i = 1; i <= n;++i){
        if(i==maxindex){
            Win += dfsWin(setBitZero(state, cur), i, left - 1);
        }
        if(getBit(state,i)&&)
    }
}
double dfsLose(int state, int left ){

}
int main()
{
    int i,j;
    while(cin>>n){
        for (i = 1; i <= n;++i){
            for (j = 1; j <= n;++j){
                cin >> WinRate[i][j];
            }
        }
        int OriState = 0;
        for (i = 1; i <= n; ++i)
            setBitOne(OriState, i);
        printf("%.6f\n", (1.0 - dfs(OriState, 1.0/C(2,n), n)));
    }
    return 0;
}