#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int N, M;//M Rows N Colums
int Orilights[20], Lights[20];
int SwitchesRecord[20];
int SuccessRecord[20],MinStep;
const int INF = 0x3f3f3f3f;
bool getBit(int n, int num) { return (num & (1 << (n - 1))) > 0; }
void setBit(int &num, int n) { num |= 1 << (n - 1); }
void switchBit(int Row,int swi){
    Lights[Row] ^= (1 << (swi - 1));
    if (swi > 1)
        Lights[Row] ^= (1 << (swi -2)); //right
    if(swi < N)
        Lights[Row] ^= (1 << (swi)); //left
    if(Row > 1)
        Lights[Row - 1] ^= (1 << (swi - 1)); //down
    if (Row < M)
        Lights[Row + 1] ^= (1 << (swi - 1)); //up
}
int main()
{
    int MaxSwitches, i, j, tmp,curStep;
    while (cin >> M >> N)
    {
        for (i = 1; i <= M;++i){
            for (j = N ; j >= 1; --j)
            {
                scanf("%d", &tmp);
                if(tmp)
                    setBit(Orilights[i], j);
            }
        }
        MaxSwitches = 1 << N;
        MinStep = INF;
        for (i = 0; i < MaxSwitches; ++i)
        {
            curStep = 0;
            memcpy(Lights, Orilights, sizeof(Orilights));
            memset(SwitchesRecord, 0, sizeof(SwitchesRecord));
            for (j = 1; j <= N; ++j)
            {
                if(getBit(j,i)) {
                    switchBit(1, j);
                    setBit(SwitchesRecord[1], j);
                    curStep++;
                }
            }
            //Deducing Following Switches.
            for (j = 1; j < M;++j){
                for (int k = 1; k <= N; ++k){
                    if(getBit(k,Lights[j])){
                        switchBit(j + 1, k);
                        setBit(SwitchesRecord[j + 1], k);
                        curStep++;
                    }
                }
            }
            if(Lights[M] == 0 && curStep < MinStep){
                memcpy(SuccessRecord, SwitchesRecord, sizeof(SwitchesRecord));
                MinStep = curStep;
            }
        }
        if(MinStep != INF)
        for (j = 1; j <= M; ++j){
            printf("%d", getBit(N, SuccessRecord[j]));
            for (int k = N - 1; k >= 1; --k)
            {
                printf(" %d", getBit(k, SuccessRecord[j]));
            }
            printf("\n");
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
