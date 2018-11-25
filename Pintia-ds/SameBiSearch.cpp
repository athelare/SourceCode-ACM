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
bool isSynp(BinTree root1,BinTree root2){

    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1->Data != root2->Data)
        return false;
    return (isSynp(root1->Left, root2->Left) && isSynp(root1->Right, root2->Right)) ||
           (isSynp(root1->Left, root2->Right) && isSynp(root1->Right, root2->Left));
}
int main()
{
    int N,L,data;
    BinTree root1, root2;
    while (~scanf("%d", &N))
    {
        if(N == 0)
            break;
        scanf("%d", &L);
        root1 = NULL;
        for (int i = 0; i < N;++i){
            scanf("%d", &data);
            root1 = Insert(root1, data);
        }#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

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
bool isSynp(BinTree root1,BinTree root2){

    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL))
        return false;
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1->Data != root2->Data)
        return false;
    return (isSynp(root1->Left, root2->Left) && isSynp(root1->Right, root2->Right)) ||
           (isSynp(root1->Left, root2->Right) && isSynp(root1->Right, root2->Left));
}
int main()
{
    int N,L,data;
    BinTree root1, root2;
    while (~scanf("%d", &N))
    {
        if(N == 0)
            break;
        scanf("%d", &L);
        root1 = NULL;
        for (int i = 0; i < N;++i){
            scanf("%d", &data);
            root1 = Insert(root1, data);
        }
        while(L--){
            root2 = NULL;
            for (int i = 0; i < N;++i){
                scanf("%d", &data);
                root2 = Insert(root2, data);
            }
            puts(isSynp(root1, root2) ? "Yes" : "No");
        }
    }
    return 0;
}
        while(L--){
            root2 = NULL;
            for (int i = 0; i < N;++i){
                scanf("%d", &data);
                root2 = Insert(root2, data);
            }
            puts(isSynp(root1, root2) ? "Yes" : "No");
        }
    }
    return 0;
}