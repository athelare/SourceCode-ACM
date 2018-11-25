#include<iostream>
using namespace std;
template<class elemType>
struct Node
{
    elemType Data;
    Node * Next;
    Node():Next(NULL){}
    Node(elemType t):Data(t),Next(NULL){}
};

template<class elemType>
struct LinkList
{
    Node<elemType>* _head;
    void init(){
        _head = new Node<elemType>;
        int n;cin>>n;
        elemType dat;
        Node<elemType>* t=_head;
        for(int i=0;i<n;++i){
            cin>>dat;
            t->Next = new Node<elemType>(dat);
            t = t->Next;
        }
    }
    void print(){
        Node<elemType>* t=_head->Next;
        while(t){
            cout<<t->Data;cout<<' ';
            t = t->Next;
        }
        cout<<endl;
    }
    template<class T>
    friend LinkList<T> PureMergeList(LinkList<T> &a,const LinkList<T> b);
};
template<class elemType>
LinkList<elemType> PureMergeList(LinkList<elemType> &a,const LinkList<elemType> b){
    Node<elemType>*ta = a._head->Next,*tb =b._head->Next,*tc = new Node<elemType>,*nhead = tc;
    while(ta && tb){
        if(tb->Data>ta->Data){
            tc->Next = ta;
            ta = ta->Next;
        }else{
            tc->Next = tb;
            tb = tb->Next;
        }
        tc = tc->Next;
    }
    tc->Next = ta?ta:tb;
    a._head=nhead;
    //purify
    ta = a._head->Next;
    while(ta){
        if(ta->Next && ta->Data == ta->Next->Data){
            ta->Next = ta->Next->Next;
        }else{
            ta = ta->Next;
        }
    }
    return a;
}
int main()
{
    LinkList<int>a,b;
    a.init(),b.init();
    a.print();
    b.print();
    PureMergeList(a,b);
    a.print();
    return 0;
}