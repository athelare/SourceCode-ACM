#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n,m;
int color[100002];
bool flag = true;
vector<int> vetices[2];
vector<int>G[100002];
void dfs(int co,int cur){
    color[cur] = co;
    if(!flag)return;
    for(auto it = G[cur].begin();it != G[cur].end();++it){
        if(color[*it]==-1){
            dfs(1-co,*it);
        }else if(color[*it]==co){
            flag = false;
            return;
        }
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&n,&m);
    memset(color,-1,sizeof(color));
    for(int i=0;i<m;++i){
        scanf("%d%d",&a,&b);
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;++i){
        if(color[i] == -1)dfs(0,i);
    }
    for(int i=0;i<n;++i){
        if(~color[i] && G[i].size()>0)vetices[color[i]].push_back(i+1);
    }
    if(flag)
    for(int i=0;i<2;++i){
        printf("%u\n",vetices[i].size());
        for(int j=0;j<vetices[i].size();++j)printf("%d ",vetices[i][j]);
        printf("\n");
    }else{
        printf("-1");
    }
    return 0;
}