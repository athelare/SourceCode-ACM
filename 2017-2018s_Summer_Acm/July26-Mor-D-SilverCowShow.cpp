#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 1001
#define INF 0x3f3f3f3f
struct Graph{
    int N,m[MAXN][MAXN];
    void init(int n,int M){
        N=n;
        memset(m,INF,sizeof(m));
        for(int i=0;i<MAXN;++i){
            m[i][i]=0;
        }
        int a,b,v;
        while(M--){
            scanf("%d%d%d",&a,&b,&v);
            if(v<m[a-1][b-1]) 
                m[a-1][b-1]= v;
        }
    }
    void SPFA(int x){
        --x;
        long long from[MAXN],to[MAXN];
        for(int i=0;i<N;++i)from[i]=to[i]=INF;
        from[x]=to[x]=0;
        bool visited[MAXN] = {false};
        queue<int>q;
        q.push(x);visited[x]=true;
        while(!q.empty()){
            int tmp = q.front();q.pop();visited[tmp]=false;
            for(int i=0;i<N;++i){
                if(from[i]>from[tmp]+m[i][tmp]){
                    from[i] = from[tmp]+m[i][tmp];
                    if(visited[i] == false){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        q.push(x);visited[x]=true;
        while(!q.empty()){
            int tmp = q.front();q.pop();visited[tmp]=false;
            for(int i=0;i<N;++i){
                if(to[i]>to[tmp]+m[tmp][i]){
                    to[i]=to[tmp]+m[tmp][i];
                    if(visited[i] == false){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }


            
        long long mxdis=0;
        for(int i=0;i<N;++i){
            if(from[i]+to[i]>mxdis)
                mxdis = from[i]+to[i];
        }
        printf("%lld\n",mxdis);
    }
};
int main()
{
    Graph g;
    int n,m,x;
    while(~scanf("%d%d%d",&n,&m,&x)){
        g.init(n,m);
        g.SPFA(x);
    }

    return 0;
}

