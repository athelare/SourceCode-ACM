#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
#define MAXN 10000
template<class T>
struct Node{
    T data;
    Node *Left,*Right;
    bool visited;
    Node(){}
    Node(T d,Node* l,Node* r):data(d),Left(l),Right(r),visited(false){}
};

char emptyFlag;
template<class T>
Node<T>* BuildTree(){
    char ch[3];
    cin>>ch;
    if((ch[0])==emptyFlag){
        return NULL;
    }
    return new Node<T>(ch[0],BuildTree<T>(),BuildTree<T>());
}


template<class T>
void traverse(Node<T>*root){
    if(!root)return;
    stack<Node<T>* >s;
    s.push(root);
    while(!s.empty()){
        Node<T>*t = s.top();
        if(!t->visited){
            t->visited=true;
            printf("%c ",t->data);
        }
        if(t->Left && !t->Left->visited){
            s.push(t->Left);
            continue;
        }
        if(t->Right && !t->Right->visited){
            s.push(t->Right);
            continue;
        }
        
        s.pop();
    }
}
int main()
{
    char find[3];
    cin>>find;
    emptyFlag=find[0];
    Node<char>*root = BuildTree<char>();
    traverse<char>(root);
    return 0;
}

