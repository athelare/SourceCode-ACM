#include<cstdio>
#include<iostream>
using namespace std;
void rotate(char a[3][3],int th,char type){
    int inii,inij;
    switch(th){
    case 1:inii=inij=0;break;
    case 4:inii=inij=1;break;
    case 2:inii=0,inij=1;break;
    case 3:inii=1,inij=0;break;
    }
    switch(type){
        case'C':
            swap(a[inii][inij],a[inii+1][inij]);
            swap(a[inii+1][inij],a[inii+1][inij+1]);
            swap(a[inii+1][inij+1],a[inii][inij+1]);

        break;
        case'R':
            swap(a[inii][inij+1],a[inii][inij]);
            swap(a[inii+1][inij+1],a[inii][inij+1]);
            swap(a[inii+1][inij],a[inii+1][inij+1]);

        break;
    }
}
int main()
{
    int T,rots;
    char operation[4];
    char a[3][3];
    cin>>T;
    while(T--){
        cin>>rots;
        cin.get();
        for(int i=0;i<3;++i,cin.get())for(int j=0;j<3;++j)a[i][j] = cin.get();
        for(int i=0;i<rots;++i){
            cin>>operation;
            rotate(a,operation[0]-'0',operation[1]);
        }
        for(int i=0;i<3;++i,puts(""))for(int j=0;j<3;++j)putchar(a[i][j]);
    }
    return 0;
}