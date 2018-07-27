#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int T, OriT;
    scanf("%d", &T);
    OriT = T;
    char S[100005];
    int record[100005];
    int Max;
    bool appear[26];
    while (T--)
    {
        scanf("%s", S);
        memset(appear, 0, sizeof(appear));
        for (int i = 0; S[i]; ++i)
        {
            appear[S[i] - 'a'] = true;
        }
        Max = 0;
        for (int i = 0; i<26; ++i){
            Max += appear[i];
        }
        printf("Case #%d: %d\n", OriT - T, Max);
    }
    return 0;
}