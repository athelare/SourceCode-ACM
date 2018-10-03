#include<iostream>
#include<cstdio>


using namespace std;
int N;
long long res = 0;
bool visited[21];
long long a[21],b[21];
int pbf[21]={0};
void dfs(int solved,int time,long long score){
    res = max(res,score);
    for(int i=0;i<N;++i){
        if(visited[i])continue;
        if((pbf[i]&solved) != pbf[i])continue;

        long long cur = time*a[i]+b[i];

        visited[i] = true;

        dfs(solved|(1<<i),time+1,score+cur);

        visited[i] = false;
    }
}
int main()
{
    int tmp,s;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a[i]>>b[i]>>s;
        for(int j=0;j<s;++j){
            cin>>tmp;
            pbf[i]|=1<<(tmp-1);
        }
    }
    dfs(0,1,0);
    cout<<res<<endl;
    return 0;
}