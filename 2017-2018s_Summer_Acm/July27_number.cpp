#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define mod 1000000003
#define MAXV 1005
//quick matrix multiplication to get fibonaci sequence.
long long getFibo(long long n);
struct matrix{
    long long m[2][2];
    matrix(int a11,int a12,int a21,int a22)
    {m[0][0]=(a11),m[0][1]=(a12),m[1][0]=(a21),m[1][1]=(a22);}
    matrix(){
        m[0][0]=m[0][1]=m[1][0]=m[1][1]=0;
    }
    friend matrix operator*(const matrix& a,const matrix& b){
        matrix c;
        for(int i=0;i<2;++i){
            for(int j=0;j<2;++j){
                for(int k=0;k<2;++k){
                    c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
                }
            }
        }
        return c;
    }
    friend matrix operator^(matrix base,long long n){
        matrix ans(1,0,0,1);
        while(n>0){
            if(n&1)ans = ans * base;
            base = base * base;
            n>>=1;
        }
        return ans;
    }
    friend long long getFibo(long long n){
        matrix base(1,1,1,0);
        matrix fn(1,0,1,0);
        matrix ans = (base^n)*fn;
        return ans.m[1][0];
    }
};
//storge the graph.
class Graph{
    int v;
    bool Gmatrix[MAXV][MAXV];
public:
    void init(int V,int m){
        v=V;
        int a,b;
        memset(Gmatrix,0,sizeof(Gmatrix));
        for(int i=0;i<m;++i){
            scanf("%d%d",&a,&b);
            Gmatrix[a-1][b-1] = Gmatrix[b-1][a-1] = true;
        }
    }
    friend void dfs(Graph G,int cu,int des,int step);
}; 

//get solution using dfs and fibonaci.
bool visited[MAXV];
long long ans;
void dfs(Graph G,int cu,int des,int step){
    if(cu == des){
        ans = (ans + getFibo(step))%mod;
        return;
    }
    visited[cu]=true;
    for(int i=0;i<G.v;++i){
        if(G.Gmatrix[cu][i] && !visited[i])dfs(G,i,des,step+1);
    }
    visited[cu]=false;
}

int main()
{
    int v,k;
    Graph G;
    while(cin>>v>>k){
        G.init(v,k);
        ans=0;
        dfs(G,0,v-1,0);
        printf("%lld\n",ans);
    }
    return 0;
}
