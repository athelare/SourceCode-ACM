
#include<iostream>
#include<cstring>
#define N 1005
using namespace std;
int Col,Row;
bool lights[N][N+1];
void Gauss(){
    int r=0,c=0;
    while(r<Row){
        if(!lights[r][r]){
            for(int i=r+1;i<Row;++i){
                if(lights[i][r]){
                    for(int j=0;j<Col;++j)swap(lights[i][j],lights[r][j]);
                    break;
                }
            }
        }
        if(!lights[r][])
        for(int i=0;i<Row;++i){
            if(i == r)continue;
            if(lights[i][r])
            for(int j=0;j<Col;++j)lights[i][j]^=lights[r][j];
        }
        ++r;
    }
}
int main()
{
    int i,j,T,t=0;
        memset(lights,0,sizeof(lights));
        for(int i=0;i<N;++i)cin>>lights[i][N];
        for(int i=0;i<H;++i)for(int j=0;j<W;++j){
            lights[i*W+j][i*W+j] = true;
            if(j>0)lights[i*W+j-1][i*W+j] = true;
            if(j<W-1)lights[i*W+j+1][i*W+j] = true;
            if(i>0)lights[(i-1)*W+j][i*W+j] = true;
            if(i<H-1)lights[(i+1)*W+j][i*W+j] = true;
        }
        Gauss();
        cout<<"PUZZLE #"<<t<<endl;
        for(int i=0;i<H;++i)for(int j=0;j<W;++j){
            cout<<(int)(lights[i*W+j][N])<<(char)(j == W-1?'\n':' ');
        }
    return 0;

}