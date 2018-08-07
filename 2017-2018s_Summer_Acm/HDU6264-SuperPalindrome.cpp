#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int T,count,len,mins,stps;
    char str[120];
    char pat[2];
    cin>>T;
    while(T--){
        scanf("%s",str);
        len = strlen(str);
        mins = len-1;
        for(int i=0;i<len-1;i+=2){
            for(int k=i+1;k<len;k+=2){
            pat[0] = str[i];
            pat[1] = str[k];
            stps = 0;
            
            for(int j = 0;j<len;++j){
                stps+=(str[j]!=pat[j%2]);
            }
            if(stps<mins)mins=stps;
        }}
        printf("%d\n",mins);
    }
    return 0;
}