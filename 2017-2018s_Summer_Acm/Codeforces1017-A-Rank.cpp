#include<iostream>
#include<algorithm>
using namespace std;
#define  P pair<int,int>
P marks[1005];
bool compare(P&a ,P&b){
    return a.second == b.second?(
        a.first<b.first
    ):a.second>b.second;
}
int main()
{
    int n,tmp;
    cin>>n;
    for(int i=0;i<n;++i){
        marks[i].first = i;
        tmp=marks[i].second = 0;
        for(int j=0;j<4;++j){
            cin>>tmp;
            marks[i].second+=tmp;
        }
    }
    sort(marks,marks+n,compare);
    for(int i=0;i<n;++i){
        if(marks[i].first == 0){
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}