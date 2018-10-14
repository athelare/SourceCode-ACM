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
        scanf("%d%d",&coef,&power);
        if(!coef)
            continue;
        cur->Next = (List)malloc(sizeof(struct Node));
        cur = cur->Next;
        cur->Next = NULL;
        cur->coef = coef;
        cur->power = power;
    }
}
List add(List a,List b){
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List cur = head, pa = a->Next, pb = b->Next;
    while(pa && pb){
        if (pa->power == pb->power && pa->coef + pb->coef == 0){
            pa = pa->Next;
            pb = pb->Next;
            continue;
        }
        cur -> Next = (List)malloc(sizeof(struct Node));
        cur =  cur->Next;
        cur->Next = NULL;
        if (pa->power == pb->power)
        {
            cur->coef = pa->coef + pb->coef;
            cur->power = pa->power;
            pa = pa->Next;
            pb = pb->Next;
        }
        else if (pa->power > pb->power)
        {
            cur->coef = pa->coef;
            cur->power = pa->power;
            pa = pa->Next;
        }else{
            cur->coef = pb->coef;
            cur->power = pb->power;
            pb = pb->Next;
        }
    }
    cur->Next = pa ? pa : pb;
    return head;
}
List NP_Mul(List num,List poly){
    List head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;

    List cur,p = poly->Next;
    cur = head;
    while (p)
    {
        cur -> Next = (List)malloc(sizeof(struct Node));
        cur = cur->Next;
        cur->Next = NULL;

        cur->power = num->power + p->power;
        cur->coef = num->coef * p->coef;
        p = p->Next;
    }
    return head;
}
List PP_Mul(List poly1,List poly2){
    List ans = (List)malloc(sizeof(struct Node));
    ans->Next = NULL;
    List p = poly1->Next;
    while (p){
        ans = add(ans, NP_Mul(p, poly2));
        p = p->Next;
    }
    return ans;
}
void Print(List poly){
    List p = poly->Next;
    if(!p)
        printf("0 0\n");
    while (p)
    {
        printf("%d %d%c", p->coef, p->power, p->Next == NULL ? '\n' : ' ');
        p = p->Next;
    }
}
int main()
{
    List poly1, poly2;
    read(&poly1);
    read(&poly2);
    
    Print(PP_Mul(poly1, poly2));
    Print(add(poly1, poly2));
    return 0;
}