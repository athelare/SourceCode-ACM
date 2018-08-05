#include<iostream>
#include<cstdio>
#include<cstring>
#define P pair<int,int>
using namespace std;
char pat[1005],str[1005];
int Next[1005];
P MatchResult[1005];
int N,M,Q,mt;
void getNext(){
    int k,j;
    Next[0] = k = -1;
    j=0;
    while(j<M){
        if(k == -1 || pat[j] == pat[k]){
            Next[++j]=++k;
        }else{
            k = Next[k];
        }
    }
}
int  match(int st){
    int i = st,j=0;
    while(i<N && j<M){
        if(j == -1 || str[i] == pat[j]){
            ++i,++j;
        }else{
            j = Next[j];
        }
    }
    if(j == M)return i-j;
    else return -1;
}
int main()
{
    mt=0;
    int s,t,li,ri;
    scanf("%d%d%d",&N,&M,&Q);
    scanf("%s%s",str,pat);
    getNext();
    int curposi=0;
    while(curposi+M<=N && (curposi = match(curposi))!= -1){
        MatchResult[mt++]=make_pair(curposi+1,curposi+M);
        curposi++;
    }
    while(Q--){
        int count = 0;
        scanf("%d%d",&s,&t);
        for(int i=0;i<mt;++i){
            if(MatchResult[i].first>=s && MatchResult[i].second<=t)count++;
            else if(MatchResult[i].second>t)break;
        }
        printf("%d\n",count);
    }
    


    return 0;
}