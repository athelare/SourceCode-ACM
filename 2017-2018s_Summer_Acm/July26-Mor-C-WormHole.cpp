#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 501
#define INF 0x3f3f3f3f
struct Graph{
    int N,m[MAXN][MAXN];
    void init(int n,int M,int W){
        N=n;
        memset(m,INF,sizeof(m));
        for(int i=0;i<MAXN;++i){
            m[i][i]=0;
        }
        int a,b,v;
        while(M--){
            scanf("%d%d%d",&a,&b,&v);
            if(v<m[a-1][b-1]) 
                m[a-1][b-1]= m[b-1][a-1] = v;
        }
        while(W--){
            scanf("%d%d%d",&a,&b,&v);
            m[a-1][b-1] = - v;
        }
    }
    void Floyd(){
        for(int k=0;k<N;++k)
        for(int i=0;i<N;++i){
        for(int j=0;j<N;++j)
            if(m[i][j] > m[i][k]+m[k][j])
                m[i][j] = m[i][k]+m[k][j];
            if(m[i][i]<0){
                printf("YES\n");
                return;
            }
        }
        printf("NO\n");
    }
};
int main()
{
    Graph g;
    int t,n,m,w;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&w);
        g.init(n,m,w);
        g.Floyd();
    }

    return 0;
}