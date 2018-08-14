#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define ull unsigned long long
const ull B1 = 9973;
const ull B2 = 100000007;
inline int v(char c){
    if(c>='A' && c<='Z')return c-'A';
    else if(c>='a' && c<='z')return c-'a'+26;
    else if(c>='0' && c<='9')return c-'0'+52;
    else if(c == '+')return 62;
    else return 63;
}
char ci[1010][200],cp[105][20];
bool image[1010][1010],pattern[110][110];
ull hash[1010][1010],tmp[1010][1010];
set<ull>pat;
multiset<ull>ori;
int w,h,p;

void computeHashp(){
    int nt=0;
    ull t1 =1,t2 = 1;
    for(int j=0;j<p;++j)t1*=B1;
    for(int i=0;i<p;++i)t2*=B2;
    //left-right
    ull e;
    for(int i=0;i<p;++i){
        e = 0;
        for(int j=0;j<p;++j)e = e*B1+pattern[i][j];
        tmp[i][0] = e;
    }
    e = 0;
    for(int i=0;i<p;++i)e = e*B2 + tmp[i][0];
    pat.insert(e);
    e = 0;
    for(int i=p-1;i>=0;--i)e = e*B2 + tmp[i][0];
    pat.insert(e);



    //right-left
    for(int i=0;i<p;++i){
        e = 0;
        for(int j=p-1;j>=0;--j)e = e*B1+pattern[i][j];
        tmp[i][0] = e;
    }
    e = 0;
    for(int i=0;i<p;++i)e = e*B2 + tmp[i][0];
    pat.insert(e);
    e = 0;
    for(int i=p-1;i>=0;--i)e = e*B2 + tmp[i][0];
    pat.insert(e);

    //down-up
    for(int i=0;i<p;++i){
        e = 0;
        for(int j=p-1;j>=0;--j)e = e*B1+pattern[j][i];
        tmp[i][0] = e;
    }
    e = 0;
    for(int i=0;i<p;++i)e = e*B2 + tmp[i][0];
    pat.insert(e);
    e = 0;
    for(int i=p-1;i>=0;--i)e = e*B2 + tmp[i][0];
    pat.insert(e);
    //up-down
    for(int i=0;i<p;++i){
        e = 0;
        for(int j=0;j<p;++j)e = e*B1+pattern[j][i];
        tmp[i][0] = e;
    }
    e = 0;
    for(int i=0;i<p;++i)e = e*B2 + tmp[i][0];
    pat.insert(e);
    e = 0;
    for(int i=p-1;i>=0;--i)e = e*B2 + tmp[i][0];
    pat.insert(e);
}
void computeHashI(){
    ull t1 =1,t2 = 1;
    for(int j=0;j<p;++j)t1*=B1;
    for(int i=0;i<p;++i)t2*=B2;
    for(int i=0;i<h;++i){
        ull e = 0;
        for(int j=0;j<p;++j)e = e*B1 + image[i][j];
        for(int j=0;j+p<=w;++j){
            tmp[i][j] = e;
            if(j+p<w)e = e*B1 - t1 * image[i][j] + image[i][j+p];
        }
    }
    for(int j=0;j+p<=w;++j){
        ull e = 0;
        for(int i=0;i<p;++i) e = e * B2 + tmp[i][j];
        for(int i=0;i+p<=h;++i){
            ori.insert(e);
            if(i+p<h)e = e*B2 - t2*tmp[i][j] + tmp[i+p][j];
        }
    }
}
int main()
{
    //freopen("/home/lijiyu/SourceCode-ACM/2017-2018s_Summer_Acm/input.txt","r",stdin);
    int i,j;
    while(~scanf("%d%d%d",&w,&h,&p) && (w+h+p)){
        for(i=0;i<h;++i)scanf("%s",ci[i]);
        for(i=0;i<p;++i)scanf("%s",cp[i]);
        for(i=0;i<h;++i)for(j=0;j<w;++j){
            image[i][j] = ((v(ci[i][j/6]) & (1 << (6-(j%6)-1))) > 0);
        }
        for(i=0;i<p;++i)for(j=0;j<p;++j){
            pattern[i][j] = ((v(cp[i][j/6]) & (1 << (6-(j%6)-1))) > 0);
        }
        //for(i=0;i<p;++i)for(j=0;j<p;++j)printf("%d%c",pattern[i][j],j == p-1?'\n':' ');
        computeHashp();
        computeHashI();
        unsigned int  all = ori.size();
        for(set<ull>::iterator it = pat.begin();it != pat.end();++it)ori.erase(*it);
        printf("%u\n",all - ori.size());
        ori.clear();
        pat.clear();
    }
    return 0;
}