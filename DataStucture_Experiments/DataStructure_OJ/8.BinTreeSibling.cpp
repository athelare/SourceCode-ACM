#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 10000
template<class T>
struct Node{
    T data;
    Node *Left,*Right,*par;
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
void traverse(Node<T>* root){
    if(root){
        if(root->Left){
            root->Left->par=root;
            traverse(root->Left);
        }
        if(root->Right){
            root->Right->par=root;
            traverse(root->Right);
        }

    }
}
int main()
{
    char find[3];
    int flag;
    cin>>find;
    emptyFlag=find[0];
    Node<char>*root = BuildTree<char>();
    cin>>find;
    cin>>flag;
    traverse<char>(root);
    Node<char>*target = Find<char>(root,find[0]);
    if(target == root){
        target = NULL;
    }
    else if(flag==0){
        if(target->par->Left == target)target=NULL;
        else target = target->par->Left;
    }else if(flag == 1){
        if(target->par->Right == target)target=NULL;
        else target = target->par->Right;
    }
    if(target == NULL){
        cout<<"NULL\n";
    }else{
        cout<<target->data;
    }
    return 0;
}

