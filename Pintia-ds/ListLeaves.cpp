#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#define Null -1
#define INIT head = tail = 0
#define PUSH(x) queue[head++] = (x)
#define TOP queue[tail]
#define POP tail++
#define empty (head==tail)
using namespace std;
struct Node{
    int left, right;
} tree[12];
int root, N,i,cur;
int count,queue[1000],head,tail;
char v[3], l[4], r[4];
bool visited[12];
int main()
{
    cin >> N;
    fill(visited, visited + N, false);
    for (i = 0; i < N; ++i)
    {
        cin >> l >> r;
        tree[i].left = l[0] == '-' ? -1 : atoi(l);
        tree[i].right = r[0] == '-' ? -1 : atoi(r);
        if(tree[i].left!=Null)
            visited[tree[i].left] = true;
        if(tree[i].right!=Null)
            visited[tree[i].right] = true;
    }
    for (i = 0; i < N;++i)if(!visited[i]){
            root = i;
            break;
        }
    INIT;
    PUSH(root);
    while(!empty){
        cur = TOP;
        POP;
        if(tree[cur].left == Null && tree[cur].right == Null){
            if(count++ == 0)
                cout << cur;
            else
                cout << ' ' << cur;
        }
        else{
            if(tree[cur].left != Null)
                PUSH(tree[cur].left);
            if(tree[cur].right != Null)
                PUSH(tree[cur].right);
        }
    }
    cout << endl;
    return 0;
}