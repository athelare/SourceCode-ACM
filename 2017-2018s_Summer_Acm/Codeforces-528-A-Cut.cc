#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
    int W,H,n,v,l,r;
    char op;
    scanf("%d%d%d",&W,&H,&n);
    getchar();
    multiset<long long>width,height,weiseg,heiseg;
    width.insert(0);width.insert(W);weiseg.insert(W);
    height.insert(0);height.insert(H);heiseg.insert(H);
    while(n--){
        scanf("%c%d",&op,&v);getchar();
        switch(op){
        case'H':
            height.insert(v);
            r = *++height.find(v);
            l = *--height.find(v);
            heiseg.erase(heiseg.find(r-l));
            heiseg.insert(r-v);
            heiseg.insert(v-l);
            printf("%I64d\n",*--heiseg.end()* *--weiseg.end());
            break;
        case 'V':
            width.insert(v);
            r = *++width.find(v);
            l = *--width.find(v);
            weiseg.erase(weiseg.find(r-l));
            weiseg.insert(r-v);
            weiseg.insert(v-l);
            printf("%I64d\n",*--heiseg.end()* *--weiseg.end());
            break;
        }
    }
    return 0;
}