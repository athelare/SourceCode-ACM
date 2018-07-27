#include<bits/stdc++.h>
using namespace std;
char a[105],c[105];
int b,d;
int main()
{
    scanf("%d%d%s%s",&b,&d,a,c);
    long long lena = strlen(a),lenc = strlen(c),alen = lena*b,clen = lenc*d,count,i,j;
    for(i=0,j=0;i<alen;++i){
        if(a[i%lena] == c[j%lenc])j++;
    }
    printf("%I64d\n",j/clen);
    return 0;
}