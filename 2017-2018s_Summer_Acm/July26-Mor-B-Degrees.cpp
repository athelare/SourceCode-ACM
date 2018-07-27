#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 301
#define INF 0x3f3f3f3f
struct Graph{
    int N,m[MAXN][MAXN];
    void init(int n,int mm){
        int p,inmovie[MAXN];
        N=n;
        memset(m,INF,sizeof(m));
        for(int i=0;i<MAXN;++i){
            m[i][i]=0;
        }
        int a,b,v;
        while(mm--){
            scanf("%d",&p);
            for(int i=0;i<p;++i)scanf("%d",&inmovie[i]);
            for(int i=0;i<p;++i)for(int j=i+1;j<p;++j)
                m[inmovie[i]-1][inmovie[j]-1] = m[inmovie[j]-1][inmovie[i]-1] = 1;
        }
    }
    void Floyd(){
        for(int k=0;k<N;++k)
        for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(m[i][j] > m[i][k]+m[k][j])
                m[i][j] = m[i][k]+m[k][j];
    }
    void solve()
    {
        Floyd();
        //for(int i=0;i<N;printf("\n"),++i)for(int j=0;j<N;++j)printf("%d ",m[i][j]);
        long long rcd[MAXN]={0};
        long long minv = INF;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(m[i][j]!=INF){
                    rcd[i]+=m[i][j];
                }
            }
            if(rcd[i]<minv){
                minv = rcd[i];
            }
        }
        printf("%lld\n",minv*100/(N-1));
    }
};
int main()
{
    Graph g;
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        g.init(n,m);
        g.solve();
    }
    return 0;
}