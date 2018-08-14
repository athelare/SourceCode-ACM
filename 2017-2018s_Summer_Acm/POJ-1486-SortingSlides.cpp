#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<pair<int,int>,pair<int,int> > Slide;
#define xmin first.first
#define xmax first.second
#define ymin second.first
#define ymax second.second

int V;
int esx,esy;
vector<vector<int> > G;
vector<int> match;
vector<bool> used;
void add_edge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
inline bool in(int x,int y,Slide& S){
    return x>=S.xmin && x<=S.xmax && y>=S.ymin && y<=S.ymax;
}
bool hungary(int u){
    used[u] = true;
    for (size_t i = 0; i < G[u].size();++i){
        if((u == esx && G[u][i] == esy)||(u == esy && G[u][i] == esx))continue;
        int v = G[u][i], w = match[v];
        if (w<0 || (!used[w]&&hungary(w))){
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int bipartitle_match(){
    int ans = 0;
    fill(match.begin(),match.end(),-1);
    for (int i = 0; i < V;++i){
        if(match[i]<0){
            fill(used.begin(),used.end(),0);
            if(hungary(i))
                ans++;
        }
    }
    return ans;
}
int main()
{
    int N,i,j,x,y,Count=1;
    while (~scanf("%d", &N) && N)
    {
        printf("Heap %d\n",Count++);
        V = N*2;
        G.resize(V);
        match.resize(V);
        used.resize(V);

        vector<Slide> slides(N);
        for(i=0;i<N;++i)
            cin>>slides[i].xmin>>slides[i].xmax>>slides[i].ymin>>slides[i].ymax;
        for(i=0;i<N;++i){
            cin>>x>>y;
            for(int j=0;j<N;++j){
                if(in(x,y,slides[j]))add_edge(j,i+N);
            }
        }
        vector<pair<int,int> >suc;
        for(i=0;i<N;++i){
            for(vector<int>::iterator it = G[i].begin();it!=G[i].end();++it){
                esx = i,esy = *it;
                if(bipartitle_match()<N)suc.push_back(make_pair(i,*it));
            }
        }
        if(suc.size() == 0)puts("none");
        else{
            for(i=0;i<suc.size();++i){
                printf("(%c,%d)%c",suc[i].first+'A',suc[i].second+1-N,i==suc.size()-1?'\n':' ');
            }
        }
        puts("");
        G.clear();
    }
    return 0;
}
