#include<iostream>
using namespace std;
int ma[105][105];
int mb[105][105];
int main()
{
    int W,H,w,h;
    cin>>H>>W;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            cin>>ma[i][j];
        }
    }
    cin>>h>>w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin>>mb[i][j];
        }
    }
    for(int i=0;i<H-h+1;++i){
        for(int j=0;j<W-w+1;++j){
            int ans = 0;
            for(int m = 0;m<h;++m){
                for(int n = 0;n<w;++n){
                    ans+=ma[i+m][j+n]*mb[m][n];
                }
            }
            cout<<ans<<(j == W-w?'\n':' ');
        }
    }
    return 0;
}