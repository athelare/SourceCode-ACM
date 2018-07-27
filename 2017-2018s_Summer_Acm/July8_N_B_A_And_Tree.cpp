#define Maxn 200005
#include<stdio.h>


struct Node{
    int value,father, edge_cost, ctll;
}Nodes[Maxn];

int n;

int main()
{
    scanf("%d", &n);
    int i,cur,curCost;
    Nodes[1].father = -1;
    for (i = 1; i <= n; ++i) {scanf("%d", &Nodes[i].value); Nodes[i].ctll = 0;}
    for (i = 2; i <= n; ++i) scanf("%d%d", &Nodes[i].father, &Nodes[i].edge_cost);
    for (i = 2; i <= n; ++i) {
        cur = i;
        curCost = 0;
        while(Nodes[cur].father!=-1 && curCost + Nodes[cur].edge_cost <= Nodes[i].value){
            Nodes[Nodes[cur].father].ctll++;
            curCost += Nodes[cur].edge_cost;
            cur = Nodes[cur].father;
        }
    }
    printf("%d", Nodes[1].ctll);
    for (i = 2; i <= n; ++i)
    {
        printf(" %d", Nodes[i].ctll);
    }
    printf("\n");
    return 0;
}
