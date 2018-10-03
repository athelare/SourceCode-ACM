#include<iostream>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
int main()en go along the circle and visit
{
    int n, d, purches[2001];
    set<int> divides;
    int sum = 0, ans = 0;
    cin >> n >> d;
    for (int i = 0; i < n;++i){
        cin >> purches[i];
    }
    for (int single = 4;d&& single > 0;--single){
        for (int i = 0;d&& i < n-1;++i){
            sum += purches[i];
            if(divides.count(i)){
                sum = 0;
                continue;
            }
            if(sum%10 == single){
                divides.insert(i);
                d--;
            }
        }
    }
    sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += purches[i];
        if(divides.count(i)){
            ans += 10 * round(1.0 * sum / 10.0);
            sum = 0;
        }
    }
    ans += 10 * round(1.0 * sum / 10.0);
    cout << ans <<endl;
    return 0;
}