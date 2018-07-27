#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool Map[23][23],visited[23][23];
int W, H,Count;
inline bool Avail(int x,int y){
    return Map[y][x] && !visited[y][x] && y > 0 && y <= H && x > 0 && x <= W;
}
void dfs(int x,int y){
    Count++;
    visited[y][x] = true;
    if (Avail(x-1,y))
        dfs(x - 1, y);
    if(Avail(x,y-1))
        dfs(x, y - 1);
    if(Avail(x+1,y))
        dfs(x + 1, y);
    if(Avail(x,y+1))
        dfs(x, y + 1);
}
int main()
{
    int i, j,x0,y0;
    char row[25];
    while (cin >> W >> H)
    {
        if(W==H && W == 0)break;
        memset(Map,true,sizeof(Map));
        memset(visited,0,sizeof(visited));
        Count = 0;
        for (i = 1; i <= H;++i){
            cin >> row;
            for (j = 1; j <= W;++j){
                if(row[j-1] == '#')
                    Map[i][j] = false;
                else if(row[j-1] == '@'){
                    x0 = j;
                    y0 = i;
                }
            }
        }
        dfs(x0,y0);
        cout << Count << endl;
    }
    return 0;
}
