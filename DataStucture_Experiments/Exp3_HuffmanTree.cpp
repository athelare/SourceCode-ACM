#include<iostream>
#include<queue>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;

#define MAXN 30
typedef struct TreeNode{
    char Data;
    int weight;
    bool leafFlag;
    TreeNode *Left,*Right;
    TreeNode():Data(0),weight(0),leafFlag(false),Left(NULL),Right(NULL){}
    TreeNode(char ch,int w):Data(ch),weight(w),leafFlag(true),Left(NULL),Right(NULL){}
    TreeNode(int w,TreeNode*L,TreeNode*R):weight(w),leafFlag(false),Left(L),Right(R){}
} *BinTree;

struct cmp{
    bool operator()(BinTree a,BinTree b){
        return a->weight > b->weight;
    }
};

int curchar=0;
char character[MAXN],*encodes[MAXN],path[10000];
void getSequence(BinTree root,int curIndex=0){
    if(root->leafFlag){
        path[curIndex]=0;
        character[curchar]=root->Data;
        encodes[curchar]=new char[curIndex+1];
        strncpy(encodes[curchar],path,curIndex+1);
        curchar++;
    }
    if(root->Left){
        path[curIndex]='0';
        getSequence(root->Left,curIndex+1);
    }
    if(root->Right){
        path[curIndex]='1';
        getSequence(root->Right,curIndex+1);
    }
}

int main()
{
    int number_Chars,choice;//字符的数量
    char ch;
    int weight;
    BinTree root,tmp,s1,s2,p;
    priority_queue<BinTree,vector<BinTree>,cmp> q;
    map<char,char*>mp;
    char inputchars[10000];

    cin>>number_Chars;
    for(int i=0;i<number_Chars;++i){
        cin>>ch>>weight;
        tmp = new TreeNode(ch,weight);
        q.push(tmp);
    }


    //通过优先队列来建立霍夫曼树
    while(q.size()>1){
        s1 = q.top();
        q.pop();
        s2 = q.top();
        q.pop();
        tmp = new TreeNode(s1->weight+s2->weight,s1,s2);
        q.push(tmp);
    }
    root = q.top();
    //先序遍历二叉树获得字符的编码顺序
    getSequence(root);
    cout<<"Codes of each character:\n";
    for(int i=0;i<number_Chars;++i){
        mp[character[i]]=encodes[i];
        cout<<character[i]<<' '<<encodes[i]<<endl;
    }
    cout<<"Enter your choice:1:encode;2:decode"<<endl;
    while(cin>>choice){
        if(choice == 1){
            cout<<"Please input strings consists only chars above.\n";
            cin>>inputchars;
            for(int i=0;inputchars[i];++i)
                cout<<mp[inputchars[i]];
            cout<<endl;
        }else if(choice == 2){
            cout<<"Enter the code:"<<endl;
            cin>>inputchars;
            p=root;
            for(int i=0;inputchars[i];++i){
                
                if(inputchars[i]=='0'){
                    if(p->Left)
                        p=p->Left;
                    else{
                        cout<<"Invalid code."<<endl;
                        break;
                    }
                }else if(inputchars[i]=='1'){
                    if(p->Right)
                        p=p->Right;
                    else{
                        cout<<"Invalid code."<<endl;
                        break;
                    }
                }
                if(p->leafFlag){
                    cout<<p->Data;
                    p=root;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}