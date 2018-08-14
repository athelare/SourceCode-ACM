#include<cstdio>
#include<vector>
#include<cstring>
#define MAXN 505
using namespace std;

int V;
bool G[MAXN][MAXN];
int match[MAXN];
bool used[MAXN];

bool hungary(int u){
    used[u] = true;
    for (size_t i = 0; i < V;++i){
        if(G[u][i] == false)continue;
        int v = i, w = match[v];
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
    int Girl,Boy,M,t=0;
    while (~scanf("%d%d%d", &Girl,&Boy,&M)&&(Girl+Boy+M))
    {
        V = Girl+Boy;
        int a,b;
        memset(G,true,sizeof(G));
        for(int i=0;i<Girl;++i)for(int j=0;j<Girl;++j){
            G[i][j] = false;
        }
        for(int i=Girl;i<Girl+Boy;++i)for(int j=Girl;j<Girl+Boy;++j){
            G[i][j] = false;
        }
        for (int i = 0; i < M; ++i){
            scanf("%d%d",&a,&b);
            --a,--b;
            G[a][Girl+b]=G[Girl+b][a] = false;
        }
        printf("Case %d: %d\n",++t, V-bipartitle_match());
    }
    return 0;
}
