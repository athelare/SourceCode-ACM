#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXV 10005
#define INF 0x3fffffff
using namespace std;
int V;
double cost[MAXV][MAXV];
long long prim()
{
    long long mincost[MAXV];
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
            mincost[u] = min(mincost[u],(long long)cost[v][u]);
        }
    }
    return res;
}

int main()
{
    int M,a,b,c;
    while(cin>>V>>M){
        for(int i=0;i<V;++i)for(int j=0;j<V;++j)cost[i][j] = INF;
        for(int i=0;i<M;++i){
            scanf("%d%d%d",&a,&b,&c);
            if(-c < cost[a-1][b-1])
                cost[a-1][b-1]=cost[b-1][a-1] = -c;
        }
        long long ans = prim();
        printf("%lld\n",ans>0?-1:-ans);
    }
    return 0;
}