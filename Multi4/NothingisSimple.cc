#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
typedef pair<int, int> P;
bool compare(P&a,P&b){
    return a.second < b.second;
}
int main()
{
    int T;
    scanf("%d", &T);
    int problems;
    P p[105];
    long long totalStudents;
    while(T--){
    scanf("%d%lld", &problems, &totalStudents);
    for (int i = 0; i < problems;++i)
        scanf("%d%d", &p[i].first, &p[i].second);
    sort(p, p + problems, compare);
    long long cur=1;
    int i;
    for (i = 0; i <= problems && cur <= totalStudents; ++i){
        if(i == problems){
            i++;
            break;
        }
        cur *= (p[i].first + p[i].second);
    }
    printf("%d\n", i-1);
    }
    return 0;
}