#include<iostream>
#include<set>
#include<cstdio>
#define MAXN 300002
using namespace std;

int mgs[MAXN]={0};

set<int>xMesg[MAXN];//storge the message index so far.
int lastk=0,n,q;

int main(){
    int op,v,cur=0,unread=0;
    set<int>::iterator it;
    scanf("%d%d",&n,&q);
    while(q--){
        scanf("%d%d",&op,&v);
        switch(op){
            case 1:{
                mgs[cur]=v;
                xMesg[v].insert(cur);
                ++cur;++unread;
                printf("%d\n",unread);
                break;
            }
            case 2:{
                unread-=xMesg[v].size();
                printf("%d\n",unread);
                for(it = xMesg[v].begin();it != xMesg[v].end();++it){
                    mgs[*it]=0;
                }
                xMesg[v].clear();
                break;
            }
            case 3:{
                for(int i=lastk;i<v;++i){
                    if(mgs[i]){
                        unread--;
                        xMesg[mgs[i]].erase(i);
                    }
                    lastk = v;
                }
                printf("%d\n",unread);
                break;
            }
        }
    }
    return 0;

}