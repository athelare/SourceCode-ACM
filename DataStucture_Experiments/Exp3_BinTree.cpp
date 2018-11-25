/**********************************************
数据结构试验三 二叉树
实验内容一：基本训练（1~9）
作者：李吉宇
学号：161210219
实验日期：2018.11.12
**C++11标准
***********************************************/
#include <iostream>
#include <stack>
#include <queue>
#include <set>
#include <functional>
#include <vector>
using namespace std;
#define ElemType char
//二叉树的存储结构
typedef struct BiTNode
{
	ElemType data;
	BiTNode *lchild,*rchild;
	bool visited;
}BiTNode,*BiTree;

/*
建立二叉树的函数,存储在连续分配的一段内存中
需要输入参数:第一行为节点个数n;
随后2~n+1行分别输入节点的数据域（字符），左孩子和右孩子(编号值)，
如果不存在左孩子或者右孩子为空则用‘-1’来代替
*/
BiTree Build()
{
	int n,lc,rc;
	char dat[3];
	scanf("%d",&n);
    //采用C++11特性
	int visited[n];
	BiTree t[n];
    //预先分配空间
    for(int i=0;i<n;++i)t[i] = new BiTNode;
	for(int i=0;i<n;++i)visited[i]=false;
	for(int i=0;i<n;++i){
		scanf("%s%d%d",dat,&lc,&rc);
		t[i]->data=dat[0];
		if(~lc){
            if(lc<-1 || lc >= n)throw(lc);
			t[i]->lchild=t[lc];
			visited[lc]=true;
		}
		else t[i]->lchild=NULL;

		if(~rc){
            if(rc<-1 || rc >= n)throw(rc);
			t[i]->rchild=t[rc];
			visited[rc]=true;
		}
		else t[i]->rchild=NULL;
	}
	for(int i=0;i<n;++i)
		if(!visited[i])
			return t[i];
    return NULL;
}
////////////////////////////////////////////////
void print(BiTree t){if(t)printf("%c ",t->data );}
void clear(BiTree t){if(t)t->visited=false;}
//分别实现先序，中序，后序遍历二叉树
//遍历通过choice进行选择，先序：choice=1，中序：2，后序：3

void Traverse(BiTree root,std::function<void(BiTree)> visit,int choice)
{
    if(!root)return;
	if(choice == 1)visit(root);
	if(root->lchild)Traverse(root->lchild,visit,choice);
	if(choice == 2)visit(root);
	if(root->rchild)Traverse(root->rchild,visit,choice);
	if(choice == 3)visit(root);
}

//非递归先序遍历算法
void Non_Recursice_Traverse(BiTree root,void visit(BiTree),int choice)
{
    if(!root)return;
	stack<BiTree>s;
	Traverse(root,clear,1);
	s.push(root);

	while(!s.empty()){
        /*
        非递归先序遍历
        先序遍历非递归实现重点在于判断某个节点是否是第一次访问。
        在节点上添加一个visited标志，每次循环都查看栈顶元素，
        如果没有被访问过，那就标记访问，并且继续看元素的左孩子与右孩子
        */
		if(choice == 1)if(!s.top()->visited){
			visit(s.top());
			s.top()->visited=true;
		}
        /*
        非递归中序遍历
        中序遍历关键看左孩子是否访问过（或者不存在）
        如果当前节点未访问，左孩子已经访问/不存在左孩子，就访问当前节点；并且标记已经访问；
        因为要给当前节点的双亲结点提示，并且要避免后序遍历时重复访问，因此必须标记当前节点已访问
        */
		if(choice == 2)if((!s.top()->visited)&&((!s.top()->lchild) ||(s.top()->lchild->visited))){
			visit(s.top());
			s.top()->visited=true;
		}

		if((s.top()->lchild)&&(!s.top()->lchild->visited)){
			s.push(s.top()->lchild);
			continue;
		}
		if((s.top()->rchild)&&(!s.top()->rchild->visited)){
			s.push(s.top()->rchild);
			continue;
		}
        /*
        非递归后序遍历
        对于后序遍历，当访问过左孩子与右孩子节点之后才访问自己，并不需要繁琐的判断
        */
        if(choice == 3){
            visit(s.top());
		    s.top()->visited=true;
        }
        /*
        如果访问过当前节点，而且孩子节点都不存在或者都访问过，那么当前节点出栈
        */
		s.pop();
	}
}

//使用队列实现层次遍历
void LayerTraverse(BiTree root,void visit(BiTree)){
    if(!root)return;
    queue<BiTree>q;
    q.push(root);
    while(!q.empty()){
        BiTree top = q.front();
        q.pop();
        visit(top);
        if(top->lchild)q.push(top->lchild);
        if(top->rchild)q.push(top->rchild);
    }
}
/*
计算二叉树的高度（递归实现）
*/
int calcHeight(BiTree root)
{
	if(!root)return 0;
	return 1+max(calcHeight(root->lchild),calcHeight(root->rchild));
}

/*
统计二叉树的叶子个数（递归实现）
*/
int countLeaves(BiTree root){
	if(root == NULL)return 0;
	if(root->lchild == NULL && root->rchild == NULL)return 1;
	return countLeaves(root->lchild)+countLeaves(root->rchild);
}
BiTree Findx(BiTree root, ElemType x){
    if(root == NULL)return NULL;
    if(root->data == x)return root;

    if (Findx(root->lchild,x))
        return Findx(root->lchild,x);
    else return Findx(root->rchild,x);
}

BiTree RemoveNode(BiTree root,ElemType x){
    BiTree found;
    while((found = Findx(root,x))!=NULL){
        //后序遍历删除该节点
        Traverse(found,[](BiTree r){delete r;},3);
        //前序遍历删除该节点在二叉树中的记录
        Traverse(root,[&found](BiTree r){
            if(r->lchild == found)r->lchild=NULL;
            if(r->rchild == found)r->rchild=NULL;
        },1);
    }
    if(found == root)return NULL;
    else return root;
}
int main()
{

    freopen("exp3_input.txt","r",stdin);
	//cout<<"Please enter the representation of the Binary Tree:\nThe first line contains a single integer n means the number of nodes,\nfollowed by n rows, each row contains three integers di,li,ri.\ndi is a single char;0<=li,ri<=n, represents the child of that node.\n";
	BiTree root=NULL;
    try{
        root=Build();
    }
    catch(int e){
        cout<<e<<" is not a valid index!"<<endl;
        return(0);
    }
    
	cout << "Preorder Traverse:(Recursive and Non-recursive)\n";
    Traverse(root,print,1);
    cout << endl;

    Non_Recursice_Traverse(root,print,1);
    cout << endl;
    
    cout << "Inorder Traverse:(Recursive and Non-recursive)\n";
    Traverse(root,print,2);
    cout << endl;

    Non_Recursice_Traverse(root,print,2);
    cout << endl;

    cout << "Postorder Traverse:(Recursive and Non-recursive)\n";
    Traverse(root,print,3);
    cout << endl;

    Non_Recursice_Traverse(root,print,3);
    cout << endl;

    cout<<"Layer Traverse: \n";
    LayerTraverse(root,print);
    cout<<endl;

    cout<<"The height of the Tree: "<< calcHeight(root)<<endl;
    cout<<"The number of leaves: "<< countLeaves(root)<<endl;
    /*下面将要删除节点并且输出删除之后的先序遍历以及中序遍历*/
    cout<<"\n\nYou can now delete some Nodes.\nJust enter the value of the node,\nand the traverse sequence of the tree will be shown.\n\n";
    char del[3];
    while(~scanf("%s",del)){
        root = RemoveNode(root,del[0]);
        cout<<"Delete Node "<<del[0]<<endl<<"Preorder && Inorder:\n";
        Traverse(root,print,1);
        cout<<endl;
        Traverse(root,print,2);
        cout<<endl<<endl;
    }
	return 0;
}