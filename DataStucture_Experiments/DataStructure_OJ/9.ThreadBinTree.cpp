#include<iostream>
#include<cstdio>
using namespace std;
#define MAXN 10000
#define child false
#define th true
template<class T>
struct Node{
    T data;
    Node *Left,*Right;
    bool lt,rt;
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

Node<char>*cur;
template<class T>
void traverse(Node<T>* root){
    if(root){
        if(root->Left){
            root->lt=child;
            traverse(root->Left);
        }else root->lt=th;
        
        root->Left=cur;
        cur->Right=root;
        cur=root;

        if(root->Right){
            root->rt=child;
            traverse(root->Right);
        }else root->rt=th;

    }
}
int main()
{
    char find[3];
    int flag;
    cin>>find;
    emptyFlag=find[0];
    Node<char>*root = BuildTree<char>();
    //cin>>find;
    //cin>>flag;

    Node<char>* head = new Node<char>;
    head->rt=th;
    cur = head;

    traverse<char>(root);
    
    cur=head->Right;
    while(cur){
        cout<<cur->data<<" ";
        cur=cur->Right;
    }
    cin>>find;
    cur=head->Right;
    while(cur){
        if(cur->data==find[0])break;
        cur=cur->Right;
    }
    cout<<endl;
    if(cur){
        cout<<find[0]<<endl;
        if(cur->Left!=head){
            cout<<cur->Left->data<<endl;
        }else cout<<"NULL\n";
        if(cur->Right!=NULL){
            cout<<cur->Right->data<<endl;
        }else cout<<"NULL\n";
    }else cout<<"NULL"<<endl;

    return 0;
}

