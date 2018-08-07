#include<iostream>
#include<vector>
using namespace std;
const int MAXN = 1000;
int V;
vector<int>G[MAXN],rG[MAXN];
vector<int>vs;
bool used[MAXN];
int cmp[MAXN];

void adde(int f,int t){
    G[f].push_back(t);
    rG[t].push_back(f);
}
void dfs(int v){
    used[v] = true;
    for(int i=0;i<G[v].size();++i){
        if(!used[G[v][i]])dfs(G[v][i]);
    }
}
int pointsNum;
int rdfs(int v,int k){
    pointsNum++;
    used[v] = true;
    cmp[v] = k;
    for(int i=0;i<G[v].size();++i){
        if(!used[rG[v][i]])rdfs(rG[v][i],k);
    }
}
int scc(){
    fill(used,used+MAXN,0);
    vs.clear();
    for(int v=0;v<V;++v){
        if(!used[v])dfs(v);
    }
    fill(used,used+MAXN,0);
    int k=0,res=0;
    for(int i=vs.size()-1;i>=0;--i){
        if(!used[vs[i]]){
            pointsNum=0;
            rdfs(vs[i],k++);
            if(pointsNum>1)res++;
        }
    }
    return k;
}
int main()
{
    int M,a,b;
    cin>>V>>M;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        adde(a,b);
    }
    cout<<scc()<<endl;
    return 0;
}