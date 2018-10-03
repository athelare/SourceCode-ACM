#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define MAXV 5050
#define INF 0x7fffffff

struct edge{int to,cap,cost,rev;};
int V;
vector<edge>G[MAXV];

inline void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}

typedef pair<int,int> P;

int N,M,dist[MAXV],prevv[MAXV],preve[MAXV],h[MAXV];
int min_cost_flow(int s,int t,int f){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist,dist+V,INF);
        dist[s] = 0;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top();que.pop();
            int v = p.second;
            if(dist[v]<p.first)continue;
            for(int i=0;i<G[v].size();++i){
                edge&e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t] == INF)return -1;
        for(int v=0;v<V;++v)h[v] += dist[v];
        int d = f;
        for(int v= t;v!=s;v = prevv[v]){
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res += d*h[t];
        for(int v = t;v != s;v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
inline int vetice(int i){return i+M;}
inline int fake(int i){return i*M+N;}
int main()
{
    int T,t,K,l,r,SUM;
    scanf("%d",&T);
    while(t++<T){
        printf("Case #%d: ",t);
        scanf("%d%d%d",&N,&M,&K);
        V = M+N*2+2;
        for(int i=0;i<N;++i){
            add_edge(vetice(i),fake(i),1,-1);
            add_edge(vetice(i),fake(i),M,0);
        for(int i=0;i<M;++i){
            scanf("%d%d",&l,&r);
            l--,r--;
            add_edge(V-2,i,0,1);
            for(int j=l;j<=r;++j){
                add_edge(i,vetice)
            }
        }
        printf("%d\n",-min_cost_flow(0,V-1,K));
        for(int i=0;i<V;++i)G[i].clear();
    }
    return 0;
}