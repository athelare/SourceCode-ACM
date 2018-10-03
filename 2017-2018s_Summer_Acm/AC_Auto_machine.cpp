#include<cstdio>
#define push(c) q[head++] = (c)
#define popStack head--;
#define pop q[tail++]
#define empty (head == tail)
#define MAXN 1000002
#define SingleMax 52
char keyWords[10002][SingleMax];
char str[MAXN];
struct Node{
    int cnt;
    Node*next[26];
    Node*fail;
    Node():cnt(0),fail(NULL){
        for(int i=0;i<26;++i)next[i] = NULL;
    }
}*q[500000],*Root;

void BuildTrie(Node*root,char words[][52],int n){
    Node*cur;
    int t;
    for(int i=0;i<n;++i){
        cur = root;
        for(int j=0;words[i][j];++j){
            t=words[i][j] - 'a';
            if(cur->next[t]==NULL){
                cur->next[t] = new Node();
                cur = cur->next[t];
            }else{
                cur = cur->next[t];
            }
        }
        cur->cnt++;
    }
}
void BuildFail(Node*root){
    int head =0,tail = 0;
    root->fail = NULL;
    push(root);
    Node*par,*p;
    while(!empty){
        par = pop;
        for(int i=0;i<26;++i){
            if(par->next[i]){
                if(par == root){
                    par->next[i]->fail = root;
                }else{
                    p = par->fail;
                    while(p){
                        if(p->next[i]){
                            par->next[i]->fail = p->next[i];
                            break;
                        }else{
                            p=p->fail;
                        }
                    }
                    if(!p)par->next[i]->fail = root;
                }
                push(par->next[i]);
            }
        }
    }
}
void init(Node *root ,char words[][52],int n){
    BuildTrie(root,words,n);
    BuildFail(root);
}
int query(Node*root,char *src){
    int i=0,count = 0,t;
    Node *p = root; 
    while(src[i]){
        t= src[i] - 'a';
        while(!p->next[t] && p!=root)p=p->fail;
        p=p->next[t];
        if(p == NULL)p=root;
        Node *tmp = p;
        while(tmp!=root){
            if(tmp->cnt){
                count+=tmp->cnt;
                tmp->cnt = 0;
            }else
                break;
            tmp = tmp->fail;
        }
        ++i;
    }
    return count;
}
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--){
        Root = new Node();
        scanf("%d",&N);
        for(int i=0;i<N;++i)scanf("%s",keyWords[i]);
        init(Root,keyWords,N);
        scanf("%s",str);
        printf("%d\n",query(Root,str));
    }
    return 0;
}
