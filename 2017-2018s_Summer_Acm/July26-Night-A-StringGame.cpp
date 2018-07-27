#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

int N,M;
int deleteList[200005];
char oriStr[200005],pat[200005];
void solve();
bool match(set<int>&left);
int main()
{
    while(~scanf("%s%s",oriStr,pat)){
        N=strlen(oriStr);
        M=strlen(pat);
        for(int i=0;i<N;++i)
            scanf("%d",&deleteList[i]);
        solve();
    }
}
void solve(){
    int L=0,R=N,M=(L+R)>>1;//[L,R)
    set<int>left(deleteList+M,deleteList+N);
    
    while(L<R-1){
        if(match(left)){
            L = M;
            M = (L+R)>>1;
            for(int i=L;i<M;++i)left.erase(deleteList[i]);
        }else{
            R = M;
            M = (L+R)>>1;
            for(int i=M;i<R;++i)left.insert(deleteList[i]);
        }
        
    }
    printf("%d\n",R-1);
}
bool match(set<int>&left){
    int j=0;
    for(int i=0;i<N&&j<M;++i){
        if(oriStr[i] == pat[j] && left.count(i+1)){
            ++j;
        }
    }
    return j == M;
}