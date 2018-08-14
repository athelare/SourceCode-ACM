#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
#define MAXV 10005
#define INF 0x7fffffff

struct edge{int to,cap,cost,rev;};
int V;
vector<edge>G[MAXV];

inline void add_edge(int from,int to,int cap,int cost){
    G[from].push_back((edge){to,cap,cost,G[to].size()});
    G[to].push_back((edge){from,0,-cost,G[from].size()-1});
}




/*Bellman-Ford,)(F*V*E)*/
/*
int dist[MAXV],prevv[MAXV],preve[MAXV];
int min_cost_flow(int s,int t,int f){
    int res = 0;
    while(f>0){
        fill(dist,dist+V,INF);
        dist[s] = 0;
        bool update = true;
        while(update){
            update = false;
            for(int v=0;v<V;++v){
                if(dist[v] == INF)continue;
                for(int i=0;i<G[v].size();++i){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to] > dist[v] + e.cost){
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if(dist[t] == INF)return -1;
        int d = f;
        for(int v = t; v != s; v = prevv[v]){
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res += d*dist[t];
        for(int v = t;v!= s;v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}*/


typedef pair<int,int> P;

int dist[MAXV],prevv[MAXV],preve[MAXV],h[MAXV];
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


int main()
{
    int W,H,h,w,f;
    char Map[102][102];
    while(~scanf("%d%d",&H,&W) && (H+W)){
        V = W*H+2;
        f=0;
        for(int i=0;i<H;++i){
            for(int j=0;j<W;++j){
                if(i>0)add_edge(i*W+j,i*W+j-W,INF,1);
                if(i<H-1)add_edge(i*W+j,i*W+j+W,INF,1);
                if(j>0)add_edge(i*W+j,i*W+j-1,INF,1);
                if(j<W-1)add_edge(i*W+j,i*W+j+1,INF,1);
            }
        }
        for(int i=0;i<H;++i)scanf("%s",&Map[i]);
        for(int i=0;i<H;++i)for(int j=0;j<W;++j){
            if(Map[i][j] == 'm'){
                add_edge(V-2,i*W+j,1,0);
                ++f;
            }
            if(Map[i][j] == 'H')add_edge(i*W+j,V-1,1,0);
        }
        printf("%d\n",min_cost_flow(V-2,V-1,f));
        for(int i=0;i<V;++i)G[i].clear();
    }
    return 0;
}