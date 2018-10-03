#include<iostream>
using namespace std;
int main()
{
    int T=0;
    char Mps[3][5];
    cin>>T;
    while(T--){
        cin>>Mps[0]>>Mps[1]>>Mps[2];
        if(Mps[0][0] == Mps[0][1] && Mps[0][2] == Mps[0][1] && Mps[0][1]!='.'){
            cout<<Mps[0][0]<<endl;
        }else if(Mps[1][0] == Mps[1][1] && Mps[1][2] == Mps[1][1]&& Mps[1][1]!='.'){
            cout<<Mps[1][0]<<endl;
        }else if(Mps[2][0] == Mps[2][1] && Mps[2][2] == Mps[2][1]&& Mps[2][1]!='.'){
            cout<<Mps[2][0]<<endl;
        }else if(Mps[0][0] == Mps[1][0] && Mps[2][0] == Mps[1][0]&& Mps[1][0]!='.'){
            cout<<Mps[0][0]<<endl;
        }else if(Mps[0][1] == Mps[1][1] && Mps[2][1] == Mps[1][1]&& Mps[1][1]!='.'){
            cout<<Mps[0][1]<<endl;
        }else if(Mps[0][2] == Mps[1][2] && Mps[2][2] == Mps[1][2]&& Mps[1][2]!='.'){
            cout<<Mps[0][2]<<endl;
        }else if(Mps[0][0] == Mps[1][1] && Mps[2][2] == Mps[1][1]&& Mps[1][1]!='.'){
            cout<<Mps[0][0]<<endl;
        }else if(Mps[0][2] == Mps[1][1] && Mps[2][0] == Mps[1][1]&& Mps[1][1]!='.'){
            cout<<Mps[0][2]<<endl;
        }else{
            cout<<"ongoing"<<endl;
        }
    }
    return 0;
}