#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define Maxn 500
int B[Maxn];
int A[Maxn][Maxn];

bool Gauss(int n){
    for (int i = 0; i < 10;++i){
        for (int j = 0; j < 10;++j){
            printf("%d", A[i][j]);
        }
        printf(" %d\n", B[i]);
    }
    printf("\n");
    int Row = n, Col = Maxn;
    int r(0);
    int PrimeCol = 0;
    for (; r < n&&PrimeCol<n; ++r)
    {
        if (A[r][PrimeCol] != 0){
            for (int j = 0; j < Row;++j){//Change to Reduced form 
                if(j==r)
                    continue;
                if (A[j][PrimeCol]){
                    for (int k = PrimeCol; k < Col;++k)
                    {
                        A[j][k] ^= A[r][k];
                    }
                    B[j] ^= B[r];
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
                    swap(B[i], B[r]);
                    break;
                }
            }
            if(!A[r][PrimeCol]){
                PrimeCol++;
                r--;//Row don't change
                continue;
            }//Check after Row Change:If there is a Prime elem.
            for (int j = 0; j < Row;++j){
                if(j==r)
                    continue;
                if (A[j][PrimeCol]){
                    for (int k = PrimeCol; k < Col;++k)
                    {
                        A[j][k] ^= A[r][k];
                    }
                    B[j] ^= B[r];
                }
            }
            PrimeCol++;
        }
    }
    for (int i = 0; i < 10;++i){
        for (int j = 0; j < 10;++j){
            printf("%d", A[i][j]);
        }
        printf(" %d\n", B[i]);
    }
    for (int i = r; i < n;++i){
        if(B[i] == 1)
            return false;
    }
    return true;
}
int main()
{

    int t(0),T,n,a,b;
    scanf("%d", &T);//T examples
    while(t++<T){
        memset(A, 0, sizeof(A));
        scanf("%d", &n); //n maps
        for (int i = 0; i < n;++i){
            scanf("%d%d", &a,&b);
            A[b - 1][a - 1] = 1;
        }
        //TO CHANGE
        for (int i = 0; i < Maxn;++i)
            B[i] = 0;
        B[0] = 1;
        int ans = Gauss(n);
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
