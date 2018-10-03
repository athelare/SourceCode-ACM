#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctype.h>
using namespace std;
char Orichar[200005];
bool orib[1000000],realb[1000000];
void writebinary(char c,bool *pos){
    int digi;
    if(isdigit(c))digi =  c-'0';
    else digi = (toupper(c)-'A'+10);
    pos[0] = digi&8;
    pos[1] = digi&4;
    pos[2] = digi&2;
    pos[3] = digi&1;
}
struct Node{
    Node *next[2];
    bool finish;
    char letter;
    Node()
    {
        next[0] = next[1] = NULL;
        finish = false;
        letter = 0;
    }
};
void insert(Node*root,char digi[],char lett){
    Node *cur=root;
    int i=0;
    while(digi[i]){

        if(cur->next[digi[i]-'0']){
            cur = cur->next[digi[i]-'0'];
        }else{
            cur->next[digi[i]-'0'] = new Node();
            cur = cur->next[digi[i]-'0'];
        }
        ++i;
    }
    cur->finish = true;
    cur->letter = lett;
}
void query(Node *root ,int &cur,bool passwd[]){
    Node *curNode = root;
    while(!(curNode->finish)){
        curNode = curNode->next[passwd[cur++]];
    }
    printf("%c",curNode->letter);
}
int main()
{
    int T;
    int n,words,wascll;
    int lenori,lenreal;
    char code[20];
    Node *root;
    scanf("%d",&T);
    while(T--){
        cin>>n>>words;
        root = new Node();
        for(int i=0;i<words;++i){
            scanf("%d%s",&wascll,code);
            insert(root,code,(char)wascll);
        }
        scanf("%s",Orichar);
        lenori = lenreal = 0;
        for(int i=0;Orichar[i];++i){
            writebinary(Orichar[i],&orib[lenori]);
            lenori+=4;
        }
        /*
        for(int i=0;i<lenori;++i){
            cout<<orib[i];
            if(i%9 == 8)cout<<endl;
        }
        cout<<endl;*/
        for(int i=0;i+9<=lenori;i+=9){
            int sum=0;
            for(int j=0;j<8;++j)sum+=orib[i+j];
            //cout << sum<<' '<< (sum&1)<<' '<<(orib[8])<<((sum&1) == orib[8])<<endl;
            if((sum&1) == orib[i+8])continue;

            memcpy(realb+lenreal,orib+i,8*sizeof(bool));
            lenreal+=8;
        }
        /*
        for(int i=0;i<lenreal;++i){
            cout<<realb[i];
            if(i%8 == 7)cout<<endl;
        }
        cout<<endl;*/
        int cur = 0;
        for(int i=0;i<n;++i){
            query(root,cur,realb);
        }
        printf("\n");
    }
    return 0;

}