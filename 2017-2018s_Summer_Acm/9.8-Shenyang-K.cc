#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int a[50]= {1,2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,
            173,311,313,317,373,1373,3137
           };

int main()
{
    int t;
    cin>>t;
    string s;
    for (int cnt=1; cnt<=t; cnt++)
    {
        cin>>s;
        if (s.length()>4)
            printf("Case #%d: 3137\n", cnt);
        else
        {
            int k;
            istringstream is(s);
            is >> k;
            int b=a[upper_bound(a, a+24, k)-a-1];
            printf("Case #%d: %d\n",cnt, b);
        }
    }
    return 0;
}