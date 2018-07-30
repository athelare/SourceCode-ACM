#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int n,mindif,sequs[15];
bool visited[15];
int getValue(vector<int> v){
    int ans=0;
    for(int i=0;i<v.size();++i){
        ans*=10;
        ans+=v[i];
    }
    return ans;

}
void dfs(int cu,vector<int>& l1,vector<int>& l2){
    if(l1.size()>n/2+1 || l2.size()>n/2+1)return;
    if(cu == n){
        if(fabs(l1.size() - l2.size())>=2)return;
        do{
            if(l1[0] == 0)continue;
            do{
                if(l2[0] == 0)continue;
                int dif = fabs(getValue(l1)-getValue(l2));
                if(mindif>dif){
                    mindif = dif;
                }
            }while(next_permutation(l2.begin(),l2.end()));
        }while(next_permutation(l1.begin(),l1.end()));
        return;
    }
    //Insert l1 and l2
    l1.push_back(sequs[cu]);
    dfs(cu+1,l1,l2);
    l1.pop_back();
    l2.push_back(sequs[cu]);
    dfs(cu+1,l1,l2);
    l2.pop_back();
}

int main()
{
    int t;
    scanf("%d",&t);
    vector<int>l1,l2;
    while(t--){
        n=0;
        mindif = 0x7fffffff;
        while(~scanf("%d",&sequs[n++]))
            if(getchar() == '\n')break;
        dfs(0,l1,l2);
        printf("%d\n",mindif);

    }
    return 0;
}