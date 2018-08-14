#include<cstdio>
#include<vector>
#include<cstring>
#define MAXN 505
using namespace std;

int V;
vector<int> G[MAXN];
int match[MAXN];
bool used[MAXN];

void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}

bool hungary(int u){
    used[u] = true;
    for (size_t i = 0; i < G[u].size();++i){
        int v = G[u][i], w = match[v];
        if (w<0 || (!used[w]&&hungary(w))){
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int bipartitle_match(){
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < V;++i){
        if(match[i]<0){
            memset(used, 0, sizeof(used));
            if(hungary(i))
                ans++;
        }
    }
    return ans;
}
int main()
{
    int n,K;
    int u, v,t;
    while (~scanf("%d", &V))
    {
        for (int i = 0; i < V; ++i){
            scanf("%d: (%d)",&u,&t);
            for(int j=0;j<t;++j){
                scanf("%d",&v);
                G[u].push_back(v);
            }
        }
        printf("%d\n", V-bipartitle_match());
        for(int i=0;i<V;++i)G[i].clear();
    }
    return 0;
}
