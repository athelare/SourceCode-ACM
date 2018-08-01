#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
struct P{
    int index;
    long long sum;
    P(int i,long long s):index(i),sum(s){}
    friend bool operator < (const P& a,const P& b){return a.sum<b.sum;}  
};
long long matrix[1003][1003];
int opR=0,opC=0;
using namespace std;
int main()
{
    priority_queue<P>Row,Col;
    int n,m,k,p;
    long long ss;
    cin>>n>>m>>k>>p;
    for(int i=1;i<=n;++i){
        ss=0;
        for(int j=1;j<=m;++j){
            scanf("%I64d",&matrix[i][j]);
            ss+=matrix[i][j];
        }
        Row.push(P(i,ss));
    }
    for(int j=1;j<=m;++j){
        ss=0;
        for(int i=1;i<=n;++i){
            ss+=matrix[i][j];
        }
        Col.push(P(j,ss));
    }
    ss=0;
    while(k--){
        if( Row.top().sum>Col.top().sum){
            P tmp = Row.top();//m cols.
            Row.pop();
            ss+=(tmp.sum-opC*p);
            opR++;
            tmp.sum-=p*m;
            Row.push(tmp);
        }else{
            P tmp = Col.top();
            Col.pop();
            ss+=(tmp.sum-opR*p);
            opC++;
            tmp.sum-=p*n;
            Col.push(tmp);
        }
    }
    printf("%I64d\n",ss);
    return 0;
}
