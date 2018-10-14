#include<iostream>
using namespace std;
int number[100000];
int main()
{
    number[0] = number[1] = 1;
    for (int i = 3; i<50;++i){
        for (int j = i; j > 0;--j){
            number[j] = number[j] + number[j - 1];
        }
        long long sum = 0;
        for (int j = 0; j < i;++j){
            sum += number[j];
            printf("%lld%c", sum, j == i - 1 ? '\n' : ' ');
        }
    }
    return 0;
}