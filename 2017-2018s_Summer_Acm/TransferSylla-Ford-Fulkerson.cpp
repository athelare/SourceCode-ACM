#include<vector>
#include<cstdio>
#include<iostream>
#define MAXV 505
using namespace std;

int V;
struct edge{int to,cap,rev;};
vector<edge>G_bak[MAXV];
vector<edge>G[MAXV];
bool used[MAXV];
void add_edge(int f,int t){
    G_bak[f].push_back((edge){t,1,G[t].size()});
    G_bak[t].push_back((edge){f,0,G[f].size()-1});
}

int dfs(int v,int t,int f){
    if (v == t)return f;
    used[v] = true;
    for(int i=0;i<G[v].size();++i){
        edge &e = G[v][i];
        if(!used[e.to] && e.cap>0){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int MaxFlow(int s,int t){
    int flow = 0;
    for(int i=0;i<V;++i){
        G[i].clear();
        G[i].insert(G[i].begin(),G_bak[i].begin(),G_bak[i].end());
    }
    while(1){
        fill(used,used+V,0);
        int f = dfs(s,t,0x7fffffff);
        if(f == 0)return flow;
        flow += f;
    }
}
bool solve(){
    for(int i=0;i<V-1;++i){
        for(int j=i+1;j<V;++j){
            if(MaxFlow(i,j)<3)return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int E,a,b;
    while(cin>>V>>E && (V+E)){
        while(E--){
            cin>>a>>b;
            add_edge(a,b);
            add_edge(b,a);
        }
        puts(solve()?"YES":"NO");
        for(int i = 0;i<V;++i)G_bak[i].clear();
    }
}