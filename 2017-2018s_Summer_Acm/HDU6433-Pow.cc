#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;

int main()
{
    int n;
    string tmp;
    map<string, int> index;
    multiset<int> seta, setb;
    int ni = 1;
    cin >> n;
    for (int i = 0; i < n;++i){
        cin >> tmp;
        if(index[tmp] == 0){
            index[tmp] = ni++;
        }
        seta.insert(index[tmp]);
    }
    for (int i = 0; i < n;++i){
        cin >> tmp;
        if(index[tmp] == 0){
            index[tmp] = ni++;
        }
        setb.insert(index[tmp]);
    }
    int sum=0;
    for (map<string, int>::iterator it = index.begin(); it != index.end();++it){
        sum += min(seta.count(it->second), setb.count(it->second));
    }
    cout << sum << endl;
    return 0;
}