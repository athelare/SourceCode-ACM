#include<cstdio>
#include<iostream>
#define MAXN 1000010
#define inf 0x3f3f3f3f  

using namespace std;  

struct node{  
    int l,r;//区间[l,r]  
    int add;//区间的延时标记   
    int mn; //区间最小值  
}tree[MAXN<<2];//一定要开到4倍多的空间  

void pushup(int index){  
    tree[index].mn = min(tree[index<<1].mn,tree[index<<1|1].mn);  
}  
void pushdown(int index){  
    //说明该区间之前更新过  
    //要想更新该区间下面的子区间，就要把上次更新该区间的值向下更新  
    if(tree[index].add){  
        //替换原来的值  
        /* 
        tree[index<<1].sum = (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add; 
        tree[index<<1|1].sum = (tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add; 
        tree[index<<1].mx = tree[index].add; 
        tree[index<<1|1].mx = tree[index].add; 
        tree[index<<1].mn = tree[index].add; 
        tree[index<<1|1].mn = tree[index].add; 
        tree[index<<1].add = tree[index].add; 
        tree[index<<1|1].add = tree[index].add; 
        tree[index].add = 0;*/  
        //在原来的值的基础上加上val  
        tree[index<<1].mn += tree[index].add;  
        tree[index<<1|1].mn += tree[index].add;  
        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;  
  
    }  
}

long long initial[MAXN];
void build(int l, int r, int index)
{
    tree[index].l = l;
    tree[index].r = r;
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){
        //scanf("%d", &tree[index].sum);
        tree[index].mn = initial[l];
        return ;  
    }  
    int mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}  
void updata(int l,int r,int index,int val){  
    if(l <= tree[index].l && r >= tree[index].r){  
        /*把原来的值替换成val,因为该区间有tree[index].r-tree[index].l+1 
        个数，所以区间和 以及 最值为： 
        */  
        /*tree[index].sum = (tree[index].r-tree[index].l+1)*val; 
        tree[index].mn = val; 
        tree[index].mx = val; 
        tree[index].add = val;//延时标记*/  
        //在原来的值的基础上加上val,因为该区间有tree[index].r-tree[index].l+1  
        //个数，所以区间和 以及 最值为：  
        tree[index].mn += val;  
        tree[index].add += val;//延时标记  
  
        return ;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,index<<1,val);  
    }  
    if(r > mid){  
        updata(l,r,index<<1|1,val);  
    }  
    pushup(index);  
}  
int query(int l,int r,int index){  
    if(l <= tree[index].l && r >= tree[index].r){  
        //return tree[index].sum;  
        //return tree[index].mx;  
        return tree[index].mn;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    int Min = inf;  
    if(l <= mid){   
        Min = min(query(l,r,index<<1),Min);  
    }
    if(r > mid){  
        Min = min(query(l,r,index<<1|1),Min);  
    }  
    return Min;  
}  
int main()
{
    int T;
    int a[1000010], b[1000010], c;
    int N;
    int n, m, q, x, y, z;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &N, &c);
        for (int i = 1; i <= N;++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= N;++i)
            scanf("%d", &b[i]);
        long long cur = c;
        for (int i = 1; i <= N; ++i)
        {
            cur = initial[i] = cur - b[i] + a[i];
        }
        build(1, N, 1);
        int start;
        for (start = 1; start <= N; ++start)
        {
            if(query(1,N,1)>=0)
                break;
            updata(1, N, 1, b[start] - a[start]);
            if(start == 1){
                updata(start, start, 1, - query(1,1,1) + query(N, N, 1) + a[1] - b[1]);
            }else{
                updata(start, start, 1, - query(start,start,1) + query(start-1, start-1, 1) + a[start] - b[start]);
            }
            //for (int i = 1; i <= N;++i)
            //    printf("%d%c", query(i, i, 1), i == N ? '\n' : ' ');
        }
        if(start == N+1)
            printf("-1\n");
        else{
            printf("%d\n", start);
        }
    } 
    return 0;  
}