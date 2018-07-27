#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool visited[102][102];
char Map[102][102];
int W, H,Count;
inline bool Avail(int x,int y){
    return Map[y][x] && !visited[y][x] && y > 0 && y <= H && x > 0 && x <= W;
}
void dfs(int x,int y){
    visited[y][x] = true;
    if (Avail(x-1,y) && Map[y][x-1] == Map[y][x])
        dfs(x - 1, y);
    if(Avail(x,y-1) && Map[y-1][x] == Map[y][x])
        dfs(x, y - 1);
    if(Avail(x+1,y) && Map[y][x+1] == Map[y][x])
        dfs(x + 1, y);
    if(Avail(x,y+1) && Map[y+1][x] == Map[y][x])
        dfs(x, y + 1);
}
int main()
{
    int i, j,x0,y0;
    char row[25];
    while (cin >> H >> W)
    {
        if(W==H && W == 0)break;
        memset(Map,true,sizeof(Map));
        memset(visited,0,sizeof(visited));
        Count = 0;
        for (i = 1; i <= H;++i){
            scanf("%s",&Map[i][1]);
        }
        for(i=1;i<=H;++i){
            for(j=1;j<=W;++j){
                if(Avail(j,i)){
                    Count++;
                    dfs(j,i);
                }
            }
        }
        cout << Count << endl;
    }
    return 0;
}
