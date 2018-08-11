#include<cstdio>
#include<iostream>
using namespace std;
int SevenPows[] = {0,7,49,343,2401,16807,117649};
bool visited[8];
int N,M,dh,dm;
bool Judge(int h,int m){
    fill(visited,visited+8,false);
    for(int i=0;i<dm;++i){
        if(visited[m%7])return false;
        visited[m%7] = true;
        m/=7;
    }
    for(int i=0;i<dh;++i){
        if(visited[h%7])return false;
        visited[h%7] = true;
        h/=7;
    }
    return true;
}
int main()
{
    int i,j;
    cin>>N>>M;
    for(i=0;i<7;++i){
        if(N<=SevenPows[i]){
            dh = i;
            break;
        }
    }
    if(i == 7){
        cout<<0<<endl;
        return 0;
    }
    for(i=0;i<7;++i){
        if(M<=SevenPows[i]){
            dm = i;
            break;
        }
    }
    if(i == 7){
        cout<<0<<endl;
        return 0;
    }
    int ans = 0;
    for(i=0;i<N;++i){
        for(j=0;j<M;++j){
            if(Judge(i,j))ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}