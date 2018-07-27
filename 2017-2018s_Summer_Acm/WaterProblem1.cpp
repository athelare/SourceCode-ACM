#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool TellDivision(char nums[]){
    int remain(0);
    for (int i = 0; nums[i];++i){
        remain *= 10;
        remain += nums[i] - '0';
        remain %= 10001;
    }
    return !remain;
}
int main()
{
    char days[10000005];
    int count(0);
    while(~scanf("%s",days)){
        cout << "Case #" << ++count << ": " << (TellDivision(days) ? "YES\n" : "NO\n");
    }
    return 0;
}
