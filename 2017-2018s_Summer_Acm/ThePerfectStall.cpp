#include<vector>
#include<iostream>
using namespace std;

int V;
const int MAXV = 405;
vector<int>G[MAXV];
int match[MAXV];
bool used[MAXV];
void add(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v){
    used[v] = true;
    for(int i=0;i<G[v].size();++i){
        int u = G[v][i],w = match[u];
        if(w<0 || !used[w] && dfs(w)){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}
int bimath()
{
    int res = 0;
    
    fill(match,match+V,-1);
    for(int v = 0;v<V;++v){
        if(match[v]<0){
            fill(used,used+V,0);
            if(dfs(v))res++;
        }
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N,M,t,des;
    while(cin>>N>>M){
        V = N+M;
        for(int i=0;i<V;++i)G[i].clear();
        for(int i=0;i<N;++i){
            cin>>t;
            for(int j=0;j<t;++j){
                cin>>des;
                add(i,N+des-1);
            }
        }
        cout<<bimath()<<endl;
    }
    return 0;
    
}