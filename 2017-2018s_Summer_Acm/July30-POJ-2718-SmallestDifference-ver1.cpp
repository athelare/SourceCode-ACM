#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int t,n,miniv,a[15];
bool visited[15];

int last;

void dfs(int cu){
    if(cu == n/2){
        int list2[20],j=0,v2,dif;
        for(int i=0;i<n;++i){
            if(!visited[i])
                list2[j++] = a[i];
        }
        //sort(list2,list2+j);
        do{
            v2=0;
            if(list2[0] == 0&& j > 1)continue;
            for(int i=0;i<j;++i)v2 = v2*10 + list2[i];
            dif = abs(last-v2);
            if(dif<miniv){miniv=dif;}
        }while(next_permutation(list2,list2+j));
        return;
    }

    for(int i=0;i<n;++i){
        if(cu == 0 && a[i] == 0)continue;
        if(!visited[i]){
            last = (last*10)+a[i];
            visited[i] = true;
            dfs(cu+1);
            last = (last-a[i])/10;
            visited[i]=false;
            
        }
    }
}

int main()
{
    char inputs[100];
    scanf("%d",&t);
    getchar();
    while(t--){
        n=0,last = 0;
        miniv = 0x3f3f3f3f;
        memset(visited,0,sizeof(visited));

        cin.getline(inputs,100);
        for(int i=0;inputs[i];++i)if(inputs[i]!=' ')a[n++]=inputs[i]-'0';
        
        dfs(0);
        printf("%d\n",miniv);

    }

    return 0;
}