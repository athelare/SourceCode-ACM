#include <stdio.h>  
#include <iostream>
using namespace std;
#define MAXN 100010
#define inf 0x3f3f3f3f  

using namespace std;
typedef int Element;
struct node{
    int l,r;//区间[l,r]  
    Element add;//区间的延时标记  
    Element sum;//区间和  
    Element mx; //区间最大值  
    Element mn; //区间最小值  
}tree[MAXN<<2];//一定要开到4倍多的空间  

void pushup(int index){
    //区间和
    tree[index].sum = tree[index<<1].sum+tree[index<<1|1].sum; 
    //最大值 
    tree[index].mx = max(tree[index<<1].mx,tree[index<<1|1].mx);  
    //最小值
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
        
        //区间和
        tree[index<<1].sum += (tree[index<<1].r-tree[index<<1].l+1)*tree[index].add;  
        tree[index<<1|1].sum +=(tree[index<<1|1].r-tree[index<<1|1].l+1)*tree[index].add;  
        //最大值
        tree[index<<1].mx += tree[index].add;  
        tree[index<<1|1].mx += tree[index].add;  
        //最小值
        tree[index<<1].mn += tree[index].add;  
        tree[index<<1|1].mn += tree[index].add;  

        tree[index<<1].add += tree[index].add;  
        tree[index<<1|1].add += tree[index].add;  
        tree[index].add = 0;  
  
    }  
}
//线段树初始化节点值(下标从一开始)
Element Initial[MAXN];
void build(int l, int r, int index = 1){
    tree[index].l = l;  
    tree[index].r = r;  
    tree[index].add = 0;//刚开始一定要清0  
    if(l == r){
        //区间和
        tree[index].sum = Initial[l];
        //最大值
        tree[index].mx = Initial[l];
        //最小值
        tree[index].mn = Initial[l];
        return;
    }  
    Element mid = (l+r)>>1;  
    build(l,mid,index<<1);  
    build(mid+1,r,index<<1|1);  
    pushup(index);  
}
//更新操作:同时更新所有的值(最大值,最小值,和),使用的时候需要将不用的删去,否则必定超时
void updata(int l,int r,Element val,int index = 1){  
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
        //区间和
        tree[index].sum += (tree[index].r-tree[index].l+1)*val;  
        //最大值
        tree[index].mx += val;
        //最小值
        tree[index].mn += val;  

        tree[index].add += val;//延时标记  
  
        return ;  
    }  
    pushdown(index);  
    Element mid = (tree[index].l+tree[index].r)>>1;  
    if(l <= mid){  
        updata(l,r,val,index<<1);  
    }  
    if(r > mid){  
        updata(l,r,val,index<<1|1);  
    }  
    pushup(index);  
}
//查询操作,区间为[l,r],最初的查询index=1.若要修改查询类别只需要修改返回值
Element query(int l,int r,int index = 1){  
    if(l <= tree[index].l && r >= tree[index].r){  
        //return tree[index].sum;  
        return tree[index].mx;  
        //return tree[index].mn;  
    }  
    pushdown(index);  
    int mid = (tree[index].l+tree[index].r)>>1;  
    
    Element Sum = 0;
    Element Max = 0;
    Element Min = inf;
    if(l <= mid){
        Sum += query(l,r,index<<1);  
        Max = max(query(l,r,index<<1),Max);  
        Min = min(query(l,r,index<<1),Min);  
    }  
    if(r > mid){  
        Sum += query(l,r,index<<1|1);  
        Max = max(query(l,r,index<<1|1),Max);  
        Min = min(query(l,r,index<<1|1),Min);  
    }  
    //return Sum;  
    return Max;  
    //return Min;  
}  
int sample()
{
    //一共n个数据,下标从一开始,存储在Initial[]中
    int n,m,q,l,r;
    Element v;
    cout << "请输入元素的个数:\n";
    cin >> n;

    cout << "请输入" << n << "个元素:\n";
    for (int i = 1; i <= n; ++i)
        cin >> Initial[i];
    build(1, n);

    cout << "请输入操作序号(1:查询区间最大值,2:区间更新):\n";
    while(cin>>q){
        if(q == 1){
            cout << "请输入区间:(1~" << n << ')' << endl;
            cin >> l >> r;
            cout << query(l, r) << endl;
        }
        else if (q == 2)
        {
            cout << "请输入区间:(1~" << n << ')' << endl;
            cin >> l >> r;
            cout << "请输入增量:\n";
            cin >> v;
            updata(l, r, v);
            cout << "Finish\n";
        }
        else
            break;
        cout << "请输入操作序号(1:查询区间最大值,2:区间更新):\n";
    }  
    return 0;  
}
int main()
{
    sample();
    return 0;
}