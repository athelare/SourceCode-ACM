#include<iostream>
#include<cstring>
using namespace std;
char Grades[200005];
int main()
{
    ios::sync_with_stdio(false);
    int lfp=-1,zp,n,i,t,last;
    bool carryFlag = false,pf = false;
    cin>>n>>t>>(Grades+1);

    for(i=1;i<=n;++i){
        if(Grades[i] == '.'){
            ++i;
            break;
        }
    }
    while(Grades[i] && t>0){
        if(Grades[i]>='5'){
            lfp = i;
            break;
        }
        ++i;
    }
    while((~lfp) && t>0 && !pf){
        
        if(Grades[lfp-1]=='.'){
            Grades[lfp-1]=0;
            Grades[lfp-2]++;
            last =lfp-2;
            pf = true;
        }else{
            Grades[lfp]=0;
            Grades[lfp-1]++;
            last = lfp-1;
        }
        
        lfp = -1;
        t--;

        if(Grades[last]>'9'){
            int c = 1;
            Grades[last] = '0';
            last--;
            while(c){
                c=0;
                if(Grades[last] == '.'){
                    Grades[last] = '\0';
                    Grades[last-1]++;
                    last-=2;
                    pf = true;
                }else if(last == '\0'){
                    carryFlag = true;
                    Grades[0] = '1';
                    break;
                }else{
                    Grades[last]++;
                }

                if(Grades[last]>'9'){
                    if(!pf)Grades[last] = '\0';
                    else Grades[last] = '0';
                    last --;
                    c=1;
                }
                if(Grades[last]>='5')lfp = last;
            }
        }else if(Grades[last]>='5'){
            lfp = last;
        }
    }
    if(carryFlag)cout<<Grades<<endl;
    else cout<<(Grades+1)<<endl;
    return 0;
}