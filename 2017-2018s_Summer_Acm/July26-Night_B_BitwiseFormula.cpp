#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
char maxv[1002],minv[1002];
int n,m;

struct digit{
    string num;
    char type;//type = 0:number;1:operation
    int opn1,opn2,op;//op:X,A,O:XOR,AND,OR
    //opn1,opn2:index of previous number.
}nums[5005];
int calc(digit& cur,int th){
        if(cur.type == 0)return cur.num[th] == '1';
        else{
            switch(cur.op){
                case'X':return (nums[cur.opn1].num[th]-'0')^(nums[cur.opn2].num[th]-'0');break;
                case'A':return (nums[cur.opn1].num[th]-'0')&(nums[cur.opn2].num[th]-'0');break;
                case'O':return (nums[cur.opn1].num[th]-'0')|(nums[cur.opn2].num[th]-'0');break;
                default: return 0;
            }
        }
    }
int main()
{
    int varCount=1;
    map<string,int> toindex;
    string name="?";
    toindex[name]=0;
    string rn,op,drop;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>name>>drop>>nums[i].num;
        toindex[name]=varCount++;
        if(nums[i].num[0] == '0'||nums[i].num[0] == '1')nums[i].type=0;
        else{
            nums[i].type=1;
            cin>>op>>rn;
            nums[i].type = op[0];
            nums[i].opn1 = toindex[nums[i].num];
            nums[i].opn2 = toindex[rn];
        }
    }
    maxv[m]=minv[m]=0;
    for(int i=0;i<m;++i){
        int count0=0,count1=0;
        nums[0].num.append("0");
        for(int j=1;j<=n;++j){
            count0+=calc(nums[j],i);
        }
        nums[0].num[i]='1';
        for(int j=1;j<=n;++j){
            count1+=calc(nums[j],i);
        }
        maxv[i] = count0<count1?'1':'0';
        minv[i] = count0>count1?'1':'0';

    }
    printf("%s\n%s\n",maxv,minv);
    return 0;
}