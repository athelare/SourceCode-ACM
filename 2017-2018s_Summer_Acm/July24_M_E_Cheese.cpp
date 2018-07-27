#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<ctype.h>
using namespace std;

typedef pair<int,int> P;
bool Map[1005][1005];
bool visited[1005][1005];
P Cheeses[12];
int W,H,N;

inline bool Avail(int h,int w){
    return  h>0 && h<=H &&
            w>0 && w<=W &&
            Map[h][w] &&
            !visited[h][w];
}
int FindShortestPath(P src,P des){
    typedef pair<pair<int,int>,int> P3;
    P3 cur;
    queue<P3>q;
    q.push(make_pair(src,0));
    while(!q.empty()){
        cur = q.front();
        if(cur.first.first == des.first &&cur.first.second == des.second){return cur.second;}
        q.pop();
        for(int i = -1;i <= 1;i += 2){
            if(Avail(cur.first.first+i,cur.first.second)){
                visited[cur.first.first+i][cur.first.second] = true;
                q.push(make_pair(make_pair(cur.first.first+i,cur.first.second),cur.second+1));
            }
            if(Avail(cur.first.first,cur.first.second+i)){
                visited[cur.first.first][cur.first.second+i] = true;
                q.push(make_pair(make_pair(cur.first.first,cur.first.second+i),cur.second+1));
            }
        }
    }
}
int main()
{
    int i,j,steps;
    char Row[1005];
    while(cin>>H>>W>>N){
        memset(Map,true,sizeof(Map));
        steps = 0;
        for(i=1;i<=H;++i){
            scanf("%s",Row);
            for(j=1;j<=W;++j){
                if(Row[j-1] == 'X')Map[i][j] = false;
                else if(Row[j-1] == 'S'){
                    Cheeses[0].first = i;
                    Cheeses[0].second = j;
                }else{
                    Cheeses[Row[j-1]-'0'].first = i;
                    Cheeses[Row[j-1]-'0'].second = j;
                }
            }
        }
        steps = 0;
        for(i=0;i<N;++i){
            memset(visited,0,sizeof(visited));
            steps += FindShortestPath(Cheeses[i],Cheeses[i+1]);
        }
        printf("%d\n",steps);
    }
    return 0;
}