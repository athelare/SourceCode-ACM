#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
int N;
string CommonString;

bool Sof(string pat,string str){
    int length = str.length();
    if(length == 0)
        return false;
    int p;
    for (int i = 0; i < length; ++i)
    {
        p = 0;
        for (int j = 0; j < length && p<pat.length(); ++j)
        {
            if(pat[p] == str[(i+j)%length])
                p++;
        }
        if (p == pat.length())
            return true;
    }
    return false;
}
int count1(int n){
    int count = 0;
    while (n != 0)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}
bool cmp(int a,int b){
    return count1(a) == count1(b) ? (a > b) : (count1(a) > count1(b));
}
void solve(string pat,string rings[])
{
    string newPattern;
    int UpperBound = (1 << (pat.length()));
    int B[256];
    for (int i = 0; i < 256;++i)
        B[i] = i + 1;
    sort(B, B + UpperBound - 1, cmp);
    
    //cout << pat << endl; for (int i = 0; i < UpperBound - 1; ++i) cout << B[i] << endl;cout << endl;

    for (int b = 0; b < UpperBound -1 ; ++b)
    {
        newPattern.clear();
        int len = pat.length();
        for (int i = pat.length() - 1; i >= 0; --i)
        {
            if (((1 << i) & B[b]) > 0)
                newPattern += pat[len - i - 1];
        }
        //cout << newPattern << endl;
        int i;
        do{
            for (i = 0; i < N; ++i)
            {
                if (!Sof(newPattern, rings[i]))
                    break;
            }
            if (i == N)
            {
                cout << newPattern << endl;
                return;
            }
        } while (next_permutation(newPattern.begin(), newPattern.end()));
    }
}
int main()
{
    int alphaRecord[11][30];

    string rings[11];
    while(cin>>N){
        memset(alphaRecord, 0, sizeof(alphaRecord));
        for (int i = 0; i < N;++i){
            rings[i].clear();
            cin >> rings[i];
            
            for (int j = 0; j < rings[i].length();++j){
                alphaRecord[i][rings[i][j] - 'a']++;
            }
        }
        CommonString.clear();
        for (int i = 0; i < 26; ++i)
        {
            int mint = 15;
            for (int j = 0; j < N;++j)
                mint = min(alphaRecord[j][i], mint);
            for (int j = 0; j < mint;++j)
                CommonString += (char)('a' + i);
        }
        //cout << CommonString << endl;
        if(CommonString.length() == 0)
            printf("0\n");
        else
            solve(CommonString,rings);
    }
    return 0;
}