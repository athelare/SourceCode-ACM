#include<algorithm>
#include<set>
#include<vector>
#include<iostream>
using namespace std;
multiset<int>gcdnum;
vector<int>ans;
int main()
{
    int n;
    int tmp;
    cin>>n;
    for(int i=0;i<n*n;++i){
        cin>>tmp;
        gcdnum.insert(tmp);
    }
    ans.push_back(*--gcdnum.end());
    gcdnum.erase(--gcdnum.end());
    for(int i=0;i<n-1;++i){
        int m = *--gcdnum.end();
        gcdnum.erase(gcdnum.find(m));
        for(auto&already:ans){
            int gd = __gcd(already,m);
            gcdnum.erase(gcdnum.find(gd));
            gcdnum.erase(gcdnum.find(gd));}
        ans.push_back(m);
    }
    for(int i=0;i<ans.size();++i)cout<<ans[i]<< ' ';
    return 0;
}
