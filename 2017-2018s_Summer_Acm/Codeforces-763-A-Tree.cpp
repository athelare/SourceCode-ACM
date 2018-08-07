#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#define MAXN 100005
using namespace std;

int N;
set<int>group[MAXN];
set<int>to[MAXN];
vector<int>G[MAXN];
int degree[MAXN],ng,nc;
bool visited[MAXN],color[MAXN];
void dfs(int ci,int cur){
    visited[cur] = true;
    group[ng].insert(cur);
    to[ng].insert(G[cur].begin(),G[cur].end());
    to[ng].insert(cur);
    for(vector<int>::iterator it =G[cur].begin();it !=G[cur].end();++it ){
        if(!visited[*it] && color[*it] == ci){
            dfs(ci,*it);
        }
    }
}
int main()
{
    int a,b;
    cin>>N;
    for(int i=0;i<N-1;++i){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);G[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    for(int i=1;i<=N;++i){
        scanf("%d",&color[i]);
    }
    for(int i=1;i<=N;++i){
        if(!visited[i]){
            dfs(color[i],i);
            ++ng;
        }
    }
    for(int i=1;i<=N;++i){
        if(degree[i]>=ng-1){
            bool flag = true;
            for(int j=0;j<ng;++j){
                if(to[j].count(i) == 0){
                    flag = false;
                }
            }
            if(flag){
                printf("YES\n%d\n",i);
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}