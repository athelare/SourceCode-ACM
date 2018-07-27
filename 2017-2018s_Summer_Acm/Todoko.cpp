#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
 
typedef pair<int,int> P;
bool usedc[10][10];
bool usedr[10][10];
bool used1[3][3][10];
int map[10][10];
bool flag = false;
vector<P> blanks;
void dfs(int n){
    if(flag)return;
    for(int i=1;i<=9;++i){
        if(!usedr[blanks[n].first][i]&&
           !usedc[blanks[n].second][i]&&
           !used1[(blanks[n].first-1)/3][(blanks[n].second-1)/3][i]){
            usedr[blanks[n].first][i]=true;
            usedc[blanks[n].second][i]=true;
            used1[(blanks[n].first-1)/3][(blanks[n].second-1)/3][i]=true;
            map[blanks[n].first][blanks[n].second]=i;
 
            if(n == blanks.size()-1){
                flag = true;
                return;
            }
            dfs(n+1);
             
            if(flag)return;
            usedr[blanks[n].first][i]=false;
            usedc[blanks[n].second][i]=false;
            used1[(blanks[n].first-1)/3][(blanks[n].second-1)/3][i]=false;
        }
    }
}
void solve()
{
    dfs(0);
}
int main()
{
int t=0,T,i,j,tmp;
scanf("%d",&T);
char line[20];
while(t++<T){
for(i=1;i<=9;++i){
    scanf("%s",line);
for(j=1;j<=9;++j){
    map[i][j] = line[j-1]-'0';
    if(map[i][j]){
        usedr[i][map[i][j]]=true;
        usedc[j][map[i][j]]=true;
        used1[(i-1)/3][(j-1)/3][map[i][j]] = true;
    }
    else{
        blanks.push_back(make_pair(i,j));
    }
}}
solve();
printf("Scenario #%d:\n", t);
for(i=1;i<=9;++i){
    for(j=1;j<=9;++j){
        printf("%d",map[i][j]);
    }
    printf("\n");
}
printf("\n");
 
 
flag = false;
memset(usedc,0,sizeof(usedc));
memset(usedr,0,sizeof(usedr));
memset(used1,0,sizeof(used1));
blanks.clear();
}
return 0;
}
