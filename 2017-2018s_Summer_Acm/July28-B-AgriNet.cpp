#include<iostream>
#include<cstdio>
#define MAXV 10000
#define INF 0x3f3f3f3f
using namespace std;
int V,cost[MAXV][MAXV];
int prim()
{
    int mincost[MAXV];
    bool used[MAXV];
    for(int i=0;i<MAXV;++i){
        mincost[i]=INF;
        used[i]=false;
    }
    mincost[0]=0;
    int res = 0;

    while(true){
        int v=-1;
        for(int u=0;u<V;++u){
            if(!used[u] &&(v == -1 || mincost[u] < mincost[v]))v=u;
        }

        if(v == -1)break;
        used[v] = true;
        res += mincost[v];
        for(int u=0;u<V;++u){
            mincost[u] = min(mincost[u],cost[v][u]);
        }
    }
    return res;
}

int main()
{
    while(cin>>V){
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j)scanf("%d",&cost[i][j]);
        }
        printf("%d\n",prim());
    }
    
}