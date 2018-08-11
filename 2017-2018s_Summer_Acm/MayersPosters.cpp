//POJ 3046AC
#include<cstdio>
#define MAXN 100010
int N;
long long Sum[MAXN<<2],Lazy[MAXN<<2];
long long A[MAXN];

void Pushup(int rt){
    Sum[rt] = Sum[rt<<1]!=Sum[rt<<1|1];
}
void Build(int l,int r,int rt){
    Lazy[rt] = 0;
    if(l == r){
        Sum[rt] = A[l];
    }else{
        int m = (l+r)>>1;
        Build(l,m,rt<<1);
        Build(m+1,r,rt<<1|1);
        Pushup(rt);
    }
}
void Pushdown(int rt,int ln,int rn){
    if(Lazy[rt]){
        Lazy[rt<<1] = Lazy[rt];
        Lazy[rt<<1|1] = Lazy[rt];
        Sum[rt<<1] = Lazy[rt]*ln;
        Sum[rt<<1|1] = Lazy[rt]*rn;
        Lazy[rt] = 0;
    }
}
void Update(int L,int R,long long C,int l,int r,int rt){
    if(L<=l && r<=R){
        Sum[rt]= C*(r-l+1);
        Lazy[rt]= C;
    }else{
        int m = (l+r)>>1;
        if(Lazy[rt])Pushdown(rt,m-l+1,r-m);
        if(L <= m) Update(L,R,C,l,m,rt<<1);
        if(R >  m) Update(L,R,C,m+1,r,rt<<1|1);
        Pushup(rt);
    }
}
long long Query(int L,int R,int l,int r,int rt){
    if(L <=l && r<=R){
        return Sum[rt];
    }else{
        int m = (l+r)>>1;
        Pushdown(rt,m-l+1,r-m);
        long long ans = 0;
        if(L<=m)ans += Query(L,R,l,m,rt<<1);
        if(R >m)ans += Query(L,R,m+1,r,rt<<1|1);
        return ans;
    }
}
int main()
{
    int Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;++i){
        scanf("%lld",&A[i]);
    }
    Build(1,N,1);
    getchar();
    char op[3];
    int a,b;
    long long c;
    for(int i=0;i<Q;++i){
        scanf("%s",op);
        if(op[0] == 'Q'){
            scanf("%d%d",&a,&b);
            printf("%lld\n",Query(a,b,1,N,1));
        }else{
            scanf("%d%d%lld",&a,&b,&c);
            Update(a,b,c,1,N,1);
        }
    }
    return 0;
}