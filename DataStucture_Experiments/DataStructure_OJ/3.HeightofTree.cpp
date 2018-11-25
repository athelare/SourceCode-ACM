#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 10000
template<class T>
struct Node{
    T data;
    Node *Left,*Right;
    Node(){}
    Node(T d,Node* l,Node* r):data(d),Left(l),Right(r){}
};

int nodeCount;
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
Node<T>* Find(Node<T>* root, T x){
    if(root == NULL)return NULL;
    if(root->data == x)return root;
    Node<T>* ans;
    if((ans = Find(root->Left,x))!=NULL)return ans;
    else return Find(root->Right,x);
}
template<class T>
int CalcHeight(Node<T>*root){
    if(root == NULL)return 0;
    return 1+max(CalcHeight(root->Left),CalcHeight(root->Right));
}
int main()
{
    //freopen("in","r",stdin);
    char find[3];
    cin>>find;
    emptyFlag=find[0];
    Node<char>*root = BuildTree<char>();
    cin>>find;
    Node<char>*target = Find<char>(root,find[0]);
    if(target == NULL){
        cout<<"No Such Node\n";
    }else{
        cout<<CalcHeight<char>(target)<<endl;
    }
    return 0;
}

