#include<iostream>
#include<cstring>
using namespace std;
const int Col = 31,Row = 30;
bool lights[30][31];
void Gauss(){
    int r=0,c=0;
    while(r<30){
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
        cout<<"PUZZLE #"<<t<<endl;
        memset(lights,0,sizeof(lights));
        for(int i=0;i<30;++i)cin>>lights[i][30];
        for(int i=0;i<5;++i)for(int j=0;j<6;++j){
            lights[i*6+j][i*6+j] = true;
            if(j>0)lights[i*6+j-1][i*6+j] = true;
            if(j<5)lights[i*6+j+1][i*6+j] = true;
            if(i>0)lights[i*6+j-6][i*6+j] = true;
            if(i<4)lights[i*6+j+6][i*6+j] = true;
        }
        Gauss();
        for(int i=0;i<5;++i)for(int j=0;j<6;++j){
            cout<<(int)(lights[i*6+j][30])<<(char)(j == 5?'\n':' ');
        }
    }
    return 0;

}