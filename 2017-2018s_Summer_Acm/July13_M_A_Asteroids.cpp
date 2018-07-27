#include<cstdio>
#include<vector>
#include<cstring>
#define MAXN 1002
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
    for (size_t i = 1; i < G[u].size();++i){
        int v = G[u][i], w = match[v];
        if (!w || (!used[w]&&hungary(w))){
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int bipartitle_match(){
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= V;++i){
        if(!match[i]){
            memset(used, 0, sizeof(used));
            if(hungary(i))
                ans++;
        }
    }
    return ans;
}
int main()
{
    int N,K;
    int u, v;
    while (~scanf("%d%d", &N, &K))
    {
        V = N * 2;
        for (int i = 1; i <= N; ++i)
            G[i].push_back(0);
        for (int i = 0; i < K;++i){
            scanf("%d%d", &u, &v);
            add_edge(u, v+N);
        }
        printf("%d\n", bipartitle_match());
    }
    return 0;
}
