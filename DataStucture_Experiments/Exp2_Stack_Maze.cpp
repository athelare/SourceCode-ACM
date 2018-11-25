#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>

using namespace std;
#define MXH 100
#define MXW 100


template<typename T>
struct Node
    {
        T data;
        Node*down;
        Node*up;
        Node():down(NULL),up(NULL){}
        Node(T d):data(d),up(NULL){}
        Node(T d,Node<T> *dow):data(d),down(dow),up(NULL){}
    };
template<typename T>
struct Stack{

    Node<T> *bottom,*top;
    Stack(){bottom=top=new Node<T>;}
    void Push(T d)
    {
        Node<T>* t = new Node<T>(d,top);
        top->up = t;
        top = t;
    }
    bool empty(){return top == bottom;}
    T Top()
    {
        if(empty())return T(0,0,0);
        return top->data;
    }
    void Pop()
    {
        if(!empty()){
            Node<T>* tmp = top;
            top = top->down;
            delete(tmp);
        }
    }
};
struct Trace
{
    int r,c,dir;
    Trace(){}
    Trace(int xx,int yy,int dd):r(xx),c(yy),dir(dd){}
};
void solve(char Map[MXH][MXW],int w,int h,int inir,int inic,int terr,int terc)
{
    bool visited[MXH][MXW];
    memset(visited,0,sizeof(bool)*MXW*MXH);
    Stack<Trace>s;
    s.Push(Trace(inir,inic,0));
    while((s.Top().c != terc || s.Top().r!= terr) && !s.empty()){
        Trace cur = s.Top();
        visited[cur.r][cur.c]=true;
        if(!visited[cur.r-1][cur.c] && Map[cur.r-1][cur.c] !='#'){
                s.Push(Trace(cur.r-1,cur.c,1));
                continue;
        }
        if(!visited[cur.r][cur.c+1] && Map[cur.r][cur.c+1] !='#'){
                s.Push(Trace(cur.r,cur.c+1,2));
                continue;
        }
        if(!visited[cur.r+1][cur.c] && Map[cur.r+1][cur.c] !='#'){
                s.Push(Trace(cur.r+1,cur.c,3));
                continue;
        }
        if(!visited[cur.r][cur.c-1] && Map[cur.r][cur.c-1] !='#'){
                s.Push(Trace(cur.r,cur.c-1,4));
                continue;
        }
        s.Pop();
    }
    if(!s.empty()){
        Node<Trace>* cur = s.bottom;
        char direction[5][7]={"Start","Up","Right","Down","Left"};
        while(cur->up){
            printf("(%2d,%2d,%6s) ",cur->up->data.r,cur->up->data.c,direction[cur->up->data.dir]);
            cur=cur->up;
        }
    }else{
        printf("Cannot reach!");
    }
    puts("");
}
int main()
{
    int w,h;
    char Map[MXH][MXW];
    //. available
    //# block
    //S start
    //T terminal
    while(cin>>w>>h){
    for(int i=1;i<=h;++i){
        scanf("%s",&Map[i][1]);
        Map[i][0] = Map[i][w+1]='#';
    }
    for(int i=1;i<=w;++i)Map[0][i]=Map[h+1][i]='#';

    int inir,inic,terr,terc;
    for(int i=1;i<=h;++i)for(int j=1;j<=w;++j)
    if(Map[i][j] == 'S'){
        inir=i;inic=j;
    }else if(Map[i][j] == 'T'){
        terr=i;terc=j;
    }
    solve(Map,w,h,inir,inic,terr,terc);}
}
