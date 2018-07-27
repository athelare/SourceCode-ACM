#include<iostream>
#include<cstdio>
#include<set>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int , int> P;
bool Map[25][25];
int W,H,desx,desy;
struct status{
    int x,y,level;
    set<P>broken;
    status(int xx,int yy,int ll,set<P>s,int dx,int dy):
        x(xx),y(yy),level(ll),broken(s){
            broken.insert(make_pair(dx,dy));
    }
    status(int xx,int yy):
        x(xx),y(yy),level(1){}
};
int main()
{
    int i,j,tmp,bx,by,fx,fy;
    while(~scanf("%d%d",&W,&H)){
        if(W==H && W == 0)break;
        memset(Map,true,sizeof(Map));
        for(i=1;i<=H;++i){
            for(j=1;j<=W;++j){
                scanf("%d",&tmp);
                switch(tmp){
                    case 0:break;
                    case 1:
                    Map[i][j] = false;break;
                    case 2:
                    by=i,bx=j;break;
                    case 3:
                    fx = j;fy = i;break;
                    default:break;
                }
            }
        }
        queue<status>q;
        set<P> s0;
        q.push(status(bx,by));
        bool flag = false;
        int step;
        while(!q.empty()){
            status tmp = q.front();
            q.pop();
            
            if(tmp.level == 11)break;

            for(i=1;tmp.x+i<=W&&!flag;++i){
                if(i==1 && (!Map[tmp.y][tmp.x+i]&&!tmp.broken.count(make_pair(tmp.x+1,tmp.y))))break;
                if(tmp.x+i == fx && tmp.y == fy){
                    flag = true;
                    step = tmp.level;
                }else
                if(!Map[tmp.y][tmp.x+i]&&!tmp.broken.count(make_pair(tmp.x+i,tmp.y))){
                    q.push(status(tmp.x+i-1,tmp.y,tmp.level+1,tmp.broken,tmp.x+i,tmp.y));
                    break;
                }
            }
            for(i=1;tmp.x-i >0&&!flag;++i){
                if(i==1 && (!Map[tmp.y][tmp.x-i]&&!tmp.broken.count(make_pair(tmp.x-1,tmp.y))))break;
                if(tmp.x-i == fx && tmp.y == fy){
                    flag = true;
                    step = tmp.level;
                }else
                if(!Map[tmp.y][tmp.x-i]&&!tmp.broken.count(make_pair(tmp.x-i,tmp.y))){
                    q.push(status(tmp.x-i+1,tmp.y,tmp.level+1,tmp.broken,tmp.x-i,tmp.y));
                    break;
                }
            }
            for(i=1;tmp.y+i<=H &&!flag;++i){
                if(i==1 && (!Map[tmp.y+1][tmp.x]&&!tmp.broken.count(make_pair(tmp.x,tmp.y+1))))break;
                if(tmp.x == fx && tmp.y+i == fy){
                    flag = true;
                    step = tmp.level;
                }else
                if(!Map[tmp.y+i][tmp.x]&&!tmp.broken.count(make_pair(tmp.x,tmp.y+i))){
                    q.push(status(tmp.x,tmp.y+i-1,tmp.level+1,tmp.broken,tmp.x,tmp.y+i));
                    break;
                }
            }
            for(i=1;tmp.y-i>0 && !flag;++i){
                if(i==1 && (!Map[tmp.y-1][tmp.x]&&!tmp.broken.count(make_pair(tmp.x,tmp.y-1))))break;
                if(tmp.x == fx && tmp.y-i == fy){
                    flag = true;
                    step = tmp.level;
                }else
                if(!Map[tmp.y-i][tmp.x]&&!tmp.broken.count(make_pair(tmp.x,tmp.y-i))){
                    q.push(status(tmp.x,tmp.y-i+1,tmp.level+1,tmp.broken,tmp.x,tmp.y-i));
                    break;
                }
            }
            if(flag)break;
        }
        if(flag){
            printf("%d\n",step);
        }else{
            puts("-1");
        }
    }
    return 0;
}
