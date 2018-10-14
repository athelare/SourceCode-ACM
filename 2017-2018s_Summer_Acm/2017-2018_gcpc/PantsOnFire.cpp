#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
vector<int> G[200];
bool visited[200];

bool dfs_reachable(int a,int b){
    visited[a] = true;
    for (vector<int>::iterator it = G[a].begin(); it != G[a].end(); ++it)
    {
        if(visited[*it])
            continue;
        if (*it == b)
            return true;
        if(dfs_reachable(*it,b))
            return true;
    }
    return false;
}
bool reachable(int a,int b){
    fill(visited, visited + 200, false);
    return dfs_reachable(a, b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, ctc = 0, ia, ib;
    string a, b, are,worse,than;
    map<string, int> Country;
    cin >> n >> m;
    while(n--){
        cin >> a >> are >> worse >> than >> b;
        if(Country[a] == 0) Country[a] = ++ctc;
        if(Country[b] == 0) Country[b] = ++ctc;
        ia = Country[a];
        ib = Country[b];
        G[ia].push_back(ib);
    }
    while(m--){
        cin >> a >> are >> worse >> than >> b;
        if(Country[a] == 0) Country[a] = ++ctc;
        if(Country[b] == 0) Country[b] = ++ctc;
        ia = Country[a];
        ib = Country[b];
        if(reachable(ia,ib))
            cout << "Fact" << endl;
        else if(reachable(ib,ia))
            cout << "Alternative Fact" << endl;
        else
            cout << "Pants on Fire" << endl;
    }
    return 0;
}
