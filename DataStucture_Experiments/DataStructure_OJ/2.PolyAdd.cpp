#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coef;
    int power;
    struct Node *Next;
};
typedef struct Node *List;
//带有头结点
void read(List *head){
    List cur;
    *head = (List)malloc(sizeof(struct Node));
    (*head)->Next = NULL;
    cur = (*head);
    int len, coef, power;
    scanf("%d", &len);
    while(len--){
        scanf("%d",&coef);
        cur->Next = (List)malloc(sizeof(struct Node));
        cur = cur->Next;
        cur->Next = NULL;
        cur->coef = coef;
        //cur->power = power;
    }
    cur = (*head)->Next;
    while(cur){
        scanf("%d",&power);
        cur->power = power;
        cur = cur->Next;
    }
}
List add(List a,List b,int opand){
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List cur = head, pa = a->Next, pb = b->Next;
    while(pa && pb){
        if (pa->power == pb->power && pa->coef + opand*pb->coef == 0){
            pa = pa->Next;
            pb = pb->Next;
            continue;
        }
        cur -> Next = (List)malloc(sizeof(struct Node));
        cur =  cur->Next;
        cur->Next = NULL;
        if (pa->power == pb->power)
        {
            cur->coef = pa->coef + opand*pb->coef;
            cur->power = pa->power;
            pa = pa->Next;
            pb = pb->Next;
        }
        else if (pa->power < pb->power)
        {
            cur->coef = pa->coef;
            cur->power = pa->power;
            pa = pa->Next;
        }else{
            cur->coef = opand*pb->coef;
            cur->power = pb->power;
            pb = pb->Next;
        }
    }
    if(pa)cur->Next=pa;
    else{
        cur->Next=pb;
        cur=cur->Next;
        while(cur){
            cur->coef*=opand;
            cur=cur->Next;
        }
    }
    
    return head;
}

void Print(List poly){
    List p = poly->Next;
    if(!p)
        printf("0 0\n");
    while (p)
    {
        printf("%d %d\n", p->coef, p->power);
        p = p->Next;
    }
    printf("\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    int choice;scanf("%d",&choice);
    List poly1, poly2;
    read(&poly1);
    read(&poly2);
    Print(poly1);
    Print(poly2);
    Print(add(poly1, poly2,choice==0?1:-1));
    return 0;
}