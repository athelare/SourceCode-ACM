#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
    multiset<string>s;
    s.insert(string("01"));
    s.insert(string("01"));
    s.insert(string("01"));
    s.insert(string("01"));
    s.insert(string("01"));
    cout<<s.count("01")<<endl;
    return 0;
}