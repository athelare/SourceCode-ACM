#include<cstdio>
#define push(c) q[head++] = (c)
#define popStack head--;
#define pop q[tail++]
#define empty (head == tail)
char keyWords[10001][52];
inline size_t convert(char c){return c-'a';}
struct Node{
    bool finish;
    int count;
    Node*next[26];
    Node*fail;
    Node():finish(false),fail(NULL),count(0){
        for(int i=0;i<26;++i)next[i] = NULL;
    }
}*q[10000];

class AC{
    Node* root;
public:
    AC(){
        root = new Node();
    }
    void BuildTrie(char words[][52],int n){
        Node*cur;
        for(int i=0;i<n;++i){
            cur = root;
            for(int j=0;words[i][j];++j){
                if(cur->next[convert(words[i][j])]==NULL){
                    cur->next[convert(words[i][j])] = new Node();
                    cur = cur->next[convert(words[i][j])];
                }else{
                    cur = cur->next[convert(words[i][j])];
                }
            }
            cur->finish = true;
        }
    }
    void BuildFail(){
        int head =0,tail = 0;
        root->fail = NULL;
        push(root);
        Node*father,*p;
        while(!empty){
            father = pop;
            for(int i=0;i<26;++i){
                if(father->next[i]){
                    if(father == root){
                        father->next[i]->fail = root;
                    }else{
                        p = father->fail;
                        while(p){
                            if(p->next[i]){
                                father->next[i]->fail = p->next[i];
                                break;
                            }else{
                                p=p->fail;
                            }
                        }
                        if(!p)father->next[i]->fail = root;
                    }
                    push(father->next[i]);
                }
            }

        }
    }
    void init(char words[][52],int n){
        BuildTrie(words,n);
        BuildFail();
    }
    int query(char *src){
        int i=0,count = 0;
        Node *cur = root; 
        while(src[i]){
            if(cur->next[convert(src[i])]){
                cur = cur->next[convert(src[i])];
                ++i;
            }else{
                cur = cur->fail;
                while(cur){
                    if(cur->next[convert(src[i])]){
                        cur = cur->next[convert(src[i])];
                        ++i;
                        break;
                    }
                }
            }
            
            if(!cur){
                cur = root;
                ++i;
            }else if(cur->finish){
                cur->count++;
                count ++;
            }
        }
        return count;
    }
};
int main()
{
    int T,N;
    char str[100000];
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;++i)scanf("%s",keyWords[i]);
        AC acm;
        acm.init(keyWords,N);
        scanf("%s",str);
        printf("%d\n",acm.query(str));
    }
    return 0;
}
