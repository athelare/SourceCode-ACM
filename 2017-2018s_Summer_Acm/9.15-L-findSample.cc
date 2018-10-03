#include<iostream>
using namespace std;

char s[1000];
int Count;
char bads[7][4] ={"AAA","BBB","CCC","ACB","BCA","CAC","CBC"}; 
bool judge(char *p){
    for(int i=0;i<7;++i){
        if(p[0] == bads[i][0] && p[1] == bads[i][1] && p[2] == bads[i][2])return false;
    }
    return true;
}
void dfs(int cur,int n){
    if(cur == n){
        for(int i=0;i<n;++i)cout<<s[i];
        cout<<endl;
        Count++;
        return;
    }
    if(cur == 0 || cur == 1){
        for(int i=0;i<3;++i){
            s[cur] = 'A'+i;
            dfs(cur+1,n);
        }
    }else{
        for(int i=0;i<3;++i){
            s[cur] = 'A'+i;
            if(judge(&s[cur-2]))
                dfs(cur+1,n);
        }
    }
}
int main()
{
    for(int i=1;i<10;++i){
        Count = 0;
        dfs(0,i);
        cout<<Count<<endl;
    }
    return 0;
}