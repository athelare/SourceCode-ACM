#include<cstdio>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define init top = 0
int top=0;
#define pop top--
#define Top s[top-1]
#define push(x) s[top++] = (x)
#define empty top == 0


struct Node
{
    int data;
    bool poped;
    Node *Left, *Right;
    Node(){
        data = 0;
        Left = Right = NULL;
    }
};
typedef Node *tree;
int ni, np,
    s[100], inorder[100], preorder[100];
tree buildTree(int il,int ir,int pl,int pr){
    if(pl == pr && il == ir)
        return NULL;
    tree root = new Node();
    root->data = preorder[pl];
    int rootp;
    for (int i = il; i < ir; ++i){
        if(inorder[i] == preorder[pl]){
            rootp = i;
            break;
        }
    }
    root->Left = buildTree(il, rootp, pl + 1, pl + rootp - il + 1);
    root->Right = buildTree(rootp + 1, ir, pl + rootp - il + 1, pr);
    return root;
}
int count = 0;
void postOrder(tree root)
{
    if(root){
        postOrder(root->Left);
        postOrder(root->Right);
        if(count++ >0)
            printf(" ");
        printf("%d",root->data);
    }
}
int main()
{
    char op[6];
    int index,N,curHave=0;
    tree p, root;
    ni = 0;
    np = 0;
    scanf("%d", &N);


    while (ni<N || np<N)
    {
        scanf("%s", op);
        switch(op[1]){
        case 'u':{
            scanf("%d", &index);
            preorder[np++] = index;
            push(index);
            break;
        }
        case 'o':{
            inorder[ni++] = Top;
            pop;
            break;
        }
        }
    }
    root = buildTree(0, N, 0, N);
    postOrder(root);
    printf("\n");
    return 0;
}