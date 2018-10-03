#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(4);
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.upper_bound(3)<<endl;
    cout<<(s.upper_bound(10) == s.end())<<endl;
    cout<<(*s.end())<<endl;
    return 0;
}