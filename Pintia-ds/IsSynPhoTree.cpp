#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#define Null -1
using namespace std;
struct Node{
    char Data;
    int left, right;
} Tree1[12], Tree2[12];
int root1, root2, N1, N2, i;
char v[3], l[4], r[4];
bool visited[12];
bool isSynp(int root1,int root2){
    if(N1 != N2)
        return false;
    if(N1 == 0)
        return true;
    if ((root1 == Null && root2 != Null) || (root1 != Null && root2 == Null))
        return false;
    if(root1 == Null && root2 == Null)
        return true;
    if(Tree1[root1].Data != Tree2[root2].Data)
        return false;
    return (isSynp(Tree1[root1].left, Tree2[root2].left) && isSynp(Tree1[root1].right, Tree2[root2].right)) ||
           (isSynp(Tree1[root1].left, Tree2[root2].right) && isSynp(Tree1[root1].right, Tree2[root2].left));
}
int main()
{
    cin >> N1;
    fill(visited, visited + N1, false);
    for (i = 0; i < N1; ++i)
    {
        cin >> v >> l >> r;
        Tree1[i].Data = v[0];
        Tree1[i].left = l[0] == '-' ? -1 : atoi(l);
        Tree1[i].right = r[0] == '-' ? -1 : atoi(r);
        if(Tree1[i].left!=Null)
            visited[Tree1[i].left] = true;
        if(Tree1[i].right!=Null)
            visited[Tree1[i].right] = true;
    }
    for (i = 0; i < N1;++i)if(!visited[i]){
            root1 = i;
            break;
        }
    cin >> N2;
    fill(visited, visited + N2, false);
    for (i = 0; i < N2; ++i)
    {
        cin >> v >> l >> r;
        Tree2[i].Data = v[0];
        Tree2[i].left = l[0] == '-' ? -1 : atoi(l);
        Tree2[i].right = r[0] == '-' ? -1 : atoi(r);
        if(Tree2[i].left!=Null)
            visited[Tree2[i].left] = true;
        if(Tree2[i].right!=Null)
            visited[Tree2[i].right] = true;
    }
    for (i = 0; i < N2;++i)if(!visited[i]){
            root2 = i;
            break;
        }
    if(isSynp(root1,root2))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}