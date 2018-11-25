#include<cstdio>
#include<iostream>
#include<string>
#define OK 0
#define ERROR -1
using namespace std;

struct base
{
    virtual int push(int elem)=0;
    virtual int pop()=0;
    virtual bool full()=0;
    virtual bool empty()=0;
};
//顺序存储栈
struct SStack:base
{
    int maxSize,*s,sp;
    SStack(int n):maxSize(n),sp(0){s=new int[5];}
    bool full(){return sp>=maxSize;}
    bool empty(){return sp == 0;}
    int push(int elem){
        if(sp<maxSize){
            s[sp++]=elem;
            return OK;
        }else return ERROR;
    }
    int pop(){
        return s[--sp];
    }
};
//链式存储栈
struct Node
{
    int elem;
    Node* Next;
    Node():elem(0),Next(NULL){}
    Node(int n):elem(n),Next(NULL){}
    Node(int n,Node* top):elem(n),Next(top){}
};
struct LStack:base
{
    Node *top,*bottom;
    LStack(){
        bottom = top = new Node;
    }
    bool full(){return false;}
    bool empty(){return top == bottom;}
    int push(int elem){
        top = new Node(elem,top);
        return OK;
    }
    int pop()
    {
        if(top == bottom)
        {
            printf("Stack is empty!\n");
            return ERROR;
        }
        int res = top->elem;
        Node *tmp = top;
        top = top->Next;
        delete tmp;
        return res;
    }
};

//顺序存储队列
struct SQueue:base
{
    int maxSize,*q,head,tail;
    SQueue(int n):maxSize(n),head(0),tail(0){q = new int[n];}
    bool full(){return (head+1)%maxSize == tail;}
    bool empty(){return head == tail;}
    int push(int elem)
    {
        //使用循环队列
        if((head+1)%maxSize != tail)
        {
            q[head]=elem;
            head = (head+1)%maxSize;
            return OK;
        }else{
            printf("Queue is full!\n");return ERROR;
        }
    }
    int pop(){
        if(head == tail){
            printf("Queue is empty!\n");return ERROR;
        }else{
            int p = tail;
            tail=(tail+1)%maxSize;
            return q[p];
            
        }
    }
};

//链式存储队列
struct LQueue:base
{
    Node *head,*tail;
    LQueue(){head=tail=new Node;}
    bool empty(){return head == tail;}
    bool full(){return false;}
    int push(int elem){
        Node *s = new Node(elem);
        head->Next = s;
        head=s;
        return OK;
    }
    int pop()
    {
        if(head == tail){
            printf("Queue is empty!\n");
            return ERROR;
        }else{
            Node* tmp = tail;
            tail = tail->Next;
            delete tmp;
            return tail->elem;
        }
    }
};
//括号的匹配
bool matchExpression(string str){
    //使用链式栈来操作
    LStack *s = new LStack();
    for(int i=0;i<str.length();++i){
        //遇到左括号一律进栈
        if(str[i] == '('||str[i] == '[')s->push(str[i]);
        else if(str[i] == ')'){
            //遇到右括号一律出栈，如果发现和相应的右括号不匹配就说明表达式不合法
            if(s->empty() || s->pop() != '(')return false;
        }else if(str[i] == ']'){
            if(s->empty() || s->pop() != '[')return false;
        }
    }
    if(s->empty())return true;
    else return false;
}
int main()
{
    int ch;
    base *s;
    printf("1.\tSequence Stack\n2.\tLink Stack\n3.\tSequence Queue\n4.\tLink Queue\n5.\t[] and () match\nPlease enter your Choice:\n");
    cin>>ch;
    if(ch == 1){
        s = new SStack(10);
    }else if(ch == 2){
        s = new LStack();
    }else if(ch == 3){
        s = new SQueue(10);
    }else if(ch == 4){
        s = new LQueue();
    }else if(ch == 5){
        printf("Please enter the mathematical expression!\n");
        string str;
        while(cin>>str)
            puts(matchExpression(str)?"Correct":"No");
        return 0;
    }
    printf("Operations:x y\nx=1:push(y)\nx=2:pop()\n");
    int x,y;
    while(cin>>x){
        if(x == 1){
            cin>>y;
            if(!s->full())
                s->push(y);
            else{
                puts("Full!");
            }
        }
        else if(x == 2)
        {
            if(!s->empty()){
                y=s->pop();
                printf("Pop element: %d\n",y);
            }else{
                printf("Empty! No element!\n");
            }
        }
    }
    return 0;
}
