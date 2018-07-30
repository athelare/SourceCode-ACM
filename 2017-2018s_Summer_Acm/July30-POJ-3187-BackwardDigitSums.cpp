#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int layer;
long long finalNum;
long long triangle[12][12];
bool used[11],found;
void dfs(int l){
    int j;
    for(int i=(int)pow(2,l);i<=finalNum && !found;++i){
        triangle[l][0] = i;
        for(j=1;j<layer-l;++j){
            triangle[l][j] = triangle[l+1][j-1] - triangle[l][j-1];
            if(triangle[l][j]<=0)break;
        }
        if(j<layer-l)continue;
        if(l == 0){
            memset(used,0,sizeof(used));
            int i;
            for(i=0;i<layer;++i){
                if(used[triangle[0][i]])break;
                used[triangle[0][i]]=true;
            }
            if(i == layer){
                for(int i=0;i<layer;++i)printf("%lld%c",triangle[0][i],i==layer-1?'\n':' ');
                found = true;
                return;
            }
        }else{
            dfs(l-1);
        }
        
    }
}
int main()
{
    while(cin>>layer>>finalNum){
        found = false;
        if(layer == 1){
            cout<<finalNum<<endl;
        }else{
            triangle[layer-1][0] = finalNum;
            dfs(layer-2);
        }
    }
    return 0;
}