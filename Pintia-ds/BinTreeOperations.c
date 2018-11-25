#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }

    return 0;
}
/* 你的代码将被嵌在这里 */
Position Find( BinTree BST, ElementType X ){
    Position p = BST;
    while(p){
        if(X > p->Data)
            p = p->Right;
        else if(X< p->Data)
            p = p->Left;
        else
            return p;
    }
    return NULL;
}
Position FindMin( BinTree BST ){
    if(!BST)
        return NULL;
    Position p = BST;
    while(p->Left){
        p = p->Left;
    }
    return p;
}
Position FindMax( BinTree BST ){
    if(!BST)
        return NULL;
    Position p = BST;
    while(p->Right){
        p = p->Right;
    }
    return p;
}
BinTree Insert( BinTree BST, ElementType X ){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
        return BST;
    }
    Position p = BST;
    while(p){
        if(X > p->Data){
            if(p->Right){
                p = p->Right;
            }else{
                p->Right = (BinTree)malloc(sizeof(struct TNode));
                p->Right->Data = X;
                p->Right->Left = NULL;
                p->Right->Right = NULL;
                return BST;
            }
        }else if(X< p->Data){
            if(p->Left)
                p = p->Left;
            else{
                p->Left = (BinTree)malloc(sizeof(struct TNode));
                p->Left->Data = X;
                p->Left->Left = NULL;
                p->Left->Right = NULL;
                return BST;
            }
        }
    }
}
BinTree Delete( BinTree BST, ElementType X ){
    Position p;
    if(!BST){
        printf("Not Found\n");
    }
    else if (X > BST->Data)
        BST->Right = Delete(BST->Right, X);
    else if(X < BST->Data)
        BST->Left = Delete(BST->Left, X);
    else{
        if(BST->Left && BST->Right){
            p = FindMin(BST->Right);
            BST->Data = p->Data;
            Delete(BST->Right, BST->Data);
        }else{
            p = BST;
            if(!BST->Left)
                BST = BST->Right;
            else if(!BST->Right)
                BST = BST->Left;
            free(p);
        }
    }
    return BST;
}