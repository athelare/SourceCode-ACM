#include<iostream>
#include<cstdio>
#include<set>
using namespace std;

int grid[5][5];
set<int>appear;

void dfs(int x,int y,int step,int value){
    if(step == 5){
        appear.insert(value);
        return;
    }
    for(int i=-1;i<=1;i+=2){
        if(x+i<0 || x+i >=5)continue;
        dfs(x+i,y,step+1,value*10+grid[x+i][y]);
    }
    for(int j=-1;j<=1;j+=2){
        if(y+j<0 || y+j >=5)continue;
        dfs(x,y+j,step+1,value*10+grid[x][y+j]);
    }
}
int main()
{
    for(int i=0;i<5;++i)for(int j=0;j<5;++j)cin>>grid[i][j];
    for(int i=0;i<5;++i)for(int j=0;j<5;++j)dfs(i,j,0,grid[i][j]);
    for(set<int>::iterator it = appear.begin();it != appear.end();++it){
        cout<<*it<<endl;
    }
    cout<<appear.size()<<endl;
    return 0;
}