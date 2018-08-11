#include<iostream>
#include<vector>
#include<iostream>
using namespace std;
int N,Q;
struct Node{
    int index,controid,minw,TotalWeight;
    vector<int>Child;
    vector<int>weight;
}nodes[300005];
bool getC[300005];
int dfsw(int Ind){
    int wht=1;
    if(nodes[Ind].Child.size()==0)nodes[Ind].minw = 0;
    else nodes[Ind].minw = 0x7fffffff;
    for(int i=0;i<nodes[Ind].Child.size();++i){
        nodes[Ind].weight[i] = dfsw(nodes[Ind].Child[i]);
        nodes[Ind].minw = min(nodes[Ind].minw,nodes[Ind].weight[i]);
        wht+=nodes[Ind].weight[i];
    }
}
int dfsc(int I,int cur){
    if(getC[I])return 0;
    for(int i=0;i<nodes[I].Child.size();++i){
        if()
    }
}
int main()
{
    int par;
    std::ios::sync_with_stdio(false);
    cin>>N>>Q;
    for(int i=2;i<=N;++i){
        cin>>par;
        nodes[par].Child.push_back(i);
        nodes[par].Child.push_back(0);
    }
    dfs(1);
}