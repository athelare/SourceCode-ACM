#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define Maxn 500
int PrimeList[Maxn];
int nPrime(0);
int A[Maxn][Maxn];
const int mod = 1000000007;

int Gauss(int n){
    int Row = n, Col = nPrime;
    int r(0);
    int PrimeCol = 0;
    for (; r < Row&&PrimeCol<nPrime; ++r)
    {
        if (A[r][PrimeCol] != 0){
            for (int j = r + 1; j < Row;++j){
                if(A[j][PrimeCol])
                    for (int k = PrimeCol; k < Col;++k)
                    {
                        A[j][k] ^= A[r][k];
                    }
            }
            PrimeCol++;
        }
        else
        {
            for (int i = r + 1; i < Row;++i){
                if(A[i][PrimeCol]){
                    for (int j = PrimeCol; j < Col;++j){
                        swap(A[i][j], A[r][j]);
                    }
                    break;
                }
            }
            if(!A[r][PrimeCol]){
                PrimeCol++;
                r--;
                continue;
            }//Check after Row Change:If there is a Prime elem.
            for (int j = r + 1; j < Row;++j){
                if(A[j][PrimeCol])
                    for (int k = PrimeCol; k < Col;++k)
                    {
                        A[j][k] ^= A[r][k];
                    }
            }
            PrimeCol++;
        }
    }
    int ppow = n - r;
    long long ans = 1;
    return (ans << ppow)%mod;
}
int main()
{
    for (int i = 2; i < 2000;++i){
        int j;
        for (j = 2; j * j <= i; ++j)
        {
            if(i%j == 0)
                break;
        }
        if(j*j>i)
            PrimeList[nPrime++] = i;
    }
    int t(0),T,n,temp;
    scanf("%d", &T);
    while(t++<T){
        scanf("%d", &n);
        for (int i = 0; i < n;++i){
            scanf("%d", &temp);
            for (int j = 0; temp != 1;++j){
                if(temp%PrimeList[j] == 0){
                    A[i][j] ^= 1;
                    temp %= PrimeList[j];
                    --j;
                }
            }
        }
        int ans = Gauss(n);
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
