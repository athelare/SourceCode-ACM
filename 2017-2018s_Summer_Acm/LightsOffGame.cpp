#include<iostream>
#include<cstring>
#define N 25
using namespace std;
const int Col = N+1,Row = N;
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
    cin>>T;
    while(t++ < T){
        
        memset(lights,0,sizeof(lights));
        for(int i=0;i<N;++i)cin>>lights[i][N];
        for(int i=0;i<5;++i)for(int j=0;j<5;++j){
            lights[i*5+j][i*5+j] = true;
            if(j>0)lights[i*5+j-1][i*5+j] = true;
            if(j<4)lights[i*5+j+1][i*5+j] = true;
            if(i>0)lights[i*5+j-5][i*5+j] = true;
            if(i<4)lights[i*5+j+5][i*5+j] = true;
        }
        Gauss();
        cout<<"PUZZLE #"<<t<<endl;
        for(int i=0;i<5;++i)for(int j=0;j<5;++j){
            cout<<(int)(lights[i*5+j][N])<<(char)(j == 4?'\n':' ');
        }
    }
    return 0;

}