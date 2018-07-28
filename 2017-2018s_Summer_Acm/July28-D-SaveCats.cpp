#include<iostream>
#include<cstring>
#include<cstdio>
#include<math.h>
#define MAXV 10005
#define INF 0x3fffffff
using namespace std;
int V,Coordinates[MAXV][2];
double cost[MAXV][MAXV];
inline double distance(int x1,int y1,int x2,int y2){
    return sqrt((double)(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double prim()
{
    double mincost[MAXV];
    bool used[MAXV];
    for(int i=0;i<V;++i){
        mincost[i]=0;
        used[i]=false;
    }
    mincost[0]=0;
    double res = 0;

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
    int M,a,b;
    double totallen;
    cin>>V>>M;
        totallen = 0;
        for(int i=0;i<V;++i)for(int j=0;j<V;++j)cost[i][j] = INF;
        for(int i=0;i<V;++i){
            scanf("%d%d",&Coordinates[i][0],&Coordinates[i][1]);
        }
        for(int i=0;i<M;++i){
            scanf("%d%d",&a,&b);
            cost[a-1][b-1]=cost[b-1][a-1] = 
            -distance(   Coordinates[a-1][0],Coordinates[a-1][1],
                        Coordinates[b-1][0],Coordinates[b-1][1]);
            totallen-=cost[a-1][b-1];
        }
        printf("%.3f\n",(totallen+prim()));
    
    return 0;
}