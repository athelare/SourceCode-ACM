#include<cstdio>
#include<iostream>

using namespace std;


int R,C;
int ColCount[10005];
int situ[11][10002];

void solve()
{
    int flip=0,MaxTime=1;
    bool flipflag[11];
    int MaxCount=0;

    for(int i=0;i<R;++i)MaxTime*=2;
    for(int flip=0;flip<MaxTime;++flip){

        for(int i=0;i<R;++i)
            flipflag[i] = (flip & (1<<i));
        
        fill(ColCount,ColCount+C,0);
        for(int i=0;i<R;++i)
        for(int j=0;j<C;++j){
            ColCount[j]+=situ[i][j] ^ flipflag[i];
        }

        int curCount = 0;
        for(int i=0;i<C;++i)curCount+=max(ColCount[i],R-ColCount[i]);

        if(curCount>MaxCount)MaxCount = curCount;
    }
    cout<<MaxCount<<endl;
}

int main(){
    while(cin>>R>>C){
        if(R+C == 0)break;
        for(int i=0;i<R;++i)for(int j=0;j<C;++j)scanf("%d",&situ[i][j]);
        solve();
    }

    return 0;
}