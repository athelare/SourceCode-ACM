
#include<vector>
#include<iostream>
#define N 10005
using namespace std;
bool PrimeFlags[N]={false};
int ComCount[N] = {0};
//True:Not Prime
int main()
{
    PrimeFlags[1] = PrimeFlags[4] = PrimeFlags[8] = PrimeFlags[9] = PrimeFlags[10] = PrimeFlags[12] = true;
    for(int i=1;i<10;++i){
        if(!PrimeFlags[i]){
            for(int j=2;i*j<=100;++j)PrimeFlags[i*j]=true;
        }
    }
    for(int i=1;i<100;++i){
        if(!PrimeFlags[i]){
            for(int j=2;i*j<N;++j)PrimeFlags[i*j]=true;
        }
    }
    vector<int>conPrimes;
    for(int i=1;i<N;++i)if(!PrimeFlags[i])conPrimes.push_back(i);
    long long sum;
    for(int i=0;i<conPrimes.size();++i){
        sum=conPrimes[i];
        ComCount[sum]++;
        for(int j=i+1;j<conPrimes.size();++j){
            sum+=conPrimes[j];
            if(sum>N)break;
            ComCount[sum]++;
        }

    }
    int n;
    while(cin>>n && n){
        cout<<ComCount[n]<<endl;
    }
    return 0;
    
}