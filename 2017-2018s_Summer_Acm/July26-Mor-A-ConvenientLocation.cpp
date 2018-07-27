#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 11
struct Graph{
    int N,m[MAXN][MAXN];
    void init(int n){
        N=0;
        memset(m,0x3f3f3f3f,sizeof(m));
        for(int i=0;i<MAXN;++i){
            m[i][i]=0;
        }
        int a,b,v;
        while(n--){
            scanf("%d%d%d",&a,&b,&v);
            N = max(N,max(b,a));
            m[a][b]=m[b][a]=v;
        }
        ++N;
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
        int rcd[MAXN]={0},minv=0x3f3f3f3f,mini;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                rcd[i]+=m[i][j];
            }
            if(rcd[i]<minv){
                minv = rcd[i];
                mini = i;
            }
        }
        printf("%d %d\n",mini,minv);
    }
};
int main()
{
    Graph g;
    int n;
    while(~scanf("%d",&n)){
        if(!n)break;
        g.init(n);
        g.solve();
    }
    return 0;
}