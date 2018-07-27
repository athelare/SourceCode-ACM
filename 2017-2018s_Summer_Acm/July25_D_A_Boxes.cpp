#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int b1,b2,b3,b4,b5,b6;
    while(cin>>b1>>b2>>b3>>b4>>b5>>b6){
        if((b1|b2|b3|b4|b5|b6) == 0)break;
        int count = b6+b5+b4;
        b1 -= min(b1,b5*11);//left cannot be used.
        int d2 = b4*5-min(b2,b4*5);//how many b2 takes up spaces get by b4.
        b1-=min(b1,d2*4);//b1 takes spaces by b4 and b2; 
        b2 -= min(b2,b4*5);

        count += b3/4;
        if(b3%4>0){
            count++;
            int last = b3%4;
            int d23 = min(b2,(4-last)*2-1);
            b1 -= min(b1,36-9*last-4*d23);
            b2 -= d23;
        }
        count+=b2/9;
        if(b2%9>0){
            count++;
            int lft = b2%9;
            b1 -=min(b1,36-4*lft);

        }
        count+=b1/36+(b1%36>0);
        printf("%d\n",count);
    }
    return 0;
}

