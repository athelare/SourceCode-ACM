#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
bool TellDivision(char nums[]){
    char *st = nums;
    char temp[20];
    bool fg1(false), fg2(false);
    long long remain = 0;

    while(strlen(st)>18){
        remain *= 1e18;
        strncpy(temp, st, 18);
        remain += atoll((temp));
        remain %= 73;
        st += 18;
    }
    if(st){
        remain *= 1e18;
        remain += atoll((st));
        remain %= 73;
    }
    if(remain%73 == 0){
        fg1 = true;
    }
    else
        fg1 = false;
    remain = 0;
    while (strlen(st) > 18)
    {
        remain *= 1e18;
        strncpy(temp, st, 18);
        remain += atoll((temp));
        remain %= 137;
        st += 18;
    }
    if(st){
        remain *= 1e18;
        remain += atoll((st));
        remain %= 137;
    }
    if(remain%137 == 0){
        fg2 = true;
    }
    else
        fg2 = false;
    return fg1 && fg2;
}
int main()
{
    char days[10000005];
    int count(0);
    while(cin>>days){
        cout << "Case #" << ++count << ": " << (TellDivision(days) ? "YES\n" : "NO\n");
    }
    return 0;
}
