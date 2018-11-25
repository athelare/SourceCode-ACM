#include<iostream>
#include<vector>
#include<queue>
using namespace std;

const int MAXN = 1000;
#define Elemt int

vector<int>G[MAXN]; //图的邻接矩阵
int N;              //顶点数，顶点从零开始编号
bool visited[MAXN]; //访问标记
Elemt Data[MAXN];   //数据域

//访问函数
int t;
void Print(Elemt e){
    if(t++)cout<<' ';
    cout<<e;
}

//深度优先遍历，递归实现
void __dfs(int index,void(*visit)(Elemt e)){
    if(visited[index])return;
    visited[index]=true;
    visit(Data[index]);

    for(vector<int>::iterator it = G[index].begin();it!=G[index].end();++it){
        __dfs(*it,visit);
    }
}
void DFS(int index,void(*visit)(Elemt e)){
    t=0;
    fill(visited,visited+N,false);
    __dfs(index,visit);
}
//广度优先遍历，队列实现
void BFS(int index,void(*visit)(Elemt e)){
    fill(visited,visited+N,false);
    t=0;
    queue<int>q;
    q.push(index);
    visited[index]=true;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        visit(Data[tmp]);
        for(vector<int>::iterator it = G[tmp].begin();it!=G[tmp].end();++it){
            if(!visited[*it]){
                visited[*it]=true;
                q.push(*it);
            }
        }

    }
}
int main()
{
    int M,choice,
        u,v;
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    //输入数据说明：第一行输入0或1,代表有向图或无向图;第二行输入顶点数N,边数M,接下来M行输入M条边(整数对,下标从零开始)
    cin>>choice>>N>>M;
    for(int i=0;i<M;++i){
        cin>>u>>v;
        G[u].push_back(v);
        if(choice)G[v].push_back(u);
    }
    for(int i=0;i<N;++i)Data[i]=i;

    cout<<"DFS"<<endl;
    DFS(0,Print);
    cout<<endl;
    cout<<"BFS"<<endl;
    BFS(0,Print);
    cout<<endl;


    return 0;

}