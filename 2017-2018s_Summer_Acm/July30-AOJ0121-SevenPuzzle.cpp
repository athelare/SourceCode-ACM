#include<cstdio>
#include<iostream>
#include<math.h>
#include<map>
#include<stdlib.h>
#include<queue>
#include<set>
using namespace std;

struct State
{
   int zeroi,num,step;
   State(int zer,int nu,int tim):
    zeroi(zer),num(nu),step(tim){}
};

set<int> visi;
inline bool unvisited(int cur){
    if(visi.count(cur))return false;
    visi.insert(cur);
    return true;
}

inline int swapd(int a,int b,int num){
    a--,b--;
    int ans = num,digia,digib;
    digia = (num/(int)pow(10,7-a))%10;
    digib = (num/(int)pow(10,7-b))%10;
    ans += (digib-digia)*(int)pow(10,7-a)+(digia-digib)*(int)pow(10,7-b);
    return ans;
}

map<int,int>ans;
void solve(int zero,int num){
    int nxts;
    queue<State>q;
    q.push(State(zero,num,0));
    while(!q.empty()){
        State cur = q.front();
        q.pop();
        switch(cur.zeroi){
        case 1:{
            if(unvisited(nxts = swapd(1,2,cur.num)))q.push(State(2,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(1,5,cur.num)))q.push(State(5,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 2:{
            if(unvisited(nxts = swapd(2,1,cur.num)))q.push(State(1,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(2,6,cur.num)))q.push(State(6,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(2,3,cur.num)))q.push(State(3,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 3:{
            if(unvisited(nxts = swapd(3,2,cur.num)))q.push(State(2,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(3,7,cur.num)))q.push(State(7,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(3,4,cur.num)))q.push(State(4,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 4:{
            if(unvisited(nxts = swapd(4,3,cur.num)))q.push(State(3,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(4,8,cur.num)))q.push(State(8,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 5:{
            if(unvisited(nxts = swapd(5,1,cur.num)))q.push(State(1,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(5,6,cur.num)))q.push(State(6,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 6:{
            if(unvisited(nxts = swapd(6,5,cur.num)))q.push(State(5,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(6,2,cur.num)))q.push(State(2,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(6,7,cur.num)))q.push(State(7,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 7:{
            if(unvisited(nxts = swapd(7,3,cur.num)))q.push(State(3,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(7,6,cur.num)))q.push(State(6,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(7,8,cur.num)))q.push(State(8,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        case 8:{
            if(unvisited(nxts = swapd(8,4,cur.num)))q.push(State(4,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            if(unvisited(nxts = swapd(8,7,cur.num)))q.push(State(7,nxts,cur.step+1)),ans[nxts] = ans[cur.num]+1;
            break;
        }
        }
    }
}
int main()
{
    char numb[20];
    int num = 1234567;
    int a,b,zeroi;
    visi.insert(1234567);
    ans[1234567] = 0;
    solve(1,1234567);
    while(~scanf("%s",&numb[0])){
        getchar();
        visi.clear();
        for(int i=1;i<8;++i){
            numb[i] = getchar();
            getchar();
        }
        numb[8] = 0;
        num = atoi(numb);
        //printf("%d\n",num);
        printf("%d\n",ans[num]);
    }
    return 0;
}