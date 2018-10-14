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
    int n,m,k;
    int u, v, t, ans;
    scanf("%d%d%d", &m, &n, &k);
    V = n + m;
    while (k--)
    {
        scanf("%d%d", &u, &v);
        add_edge(u-1, v+m-1);
    }
    ans = bipartitle_match();
    memset(used, false, V);
    for (int i = 0; i < m;++i){
        if(match[i]!=-1)
            used[match[i]] = true;
    }
    int Umatch = 0;
    for (int i = 0; i < m; ++i)
    {
        int um = 0;
        for (vector<int>::iterator it = G[i].begin(); it != G[i].end();++it){
            if(!used[*it])
                um++;
        }
        if(um>2)
            um = 2;
        Umatch = max(Umatch, um);
    }
    ans += Umatch;
    printf("%d\n", ans);
    return 0;
}
