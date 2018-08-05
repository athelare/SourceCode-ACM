#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
char letters[55];
int main()
{
    cin>>n>>k;
    cin>>letters;
    int sum=0;
    sort(letters,letters+n);
    sum+=letters[0]-'a'+1;
    char last = letters[0];
    for(int i=1,j=1;i<k;++i){
        while(letters[j] - last<=1 && j<n)++j;
        if(j == n){
            cout<<"-1"<<endl;
            return 0;
        }
        sum+=letters[j]-'a'+1;
        last = letters[j];
    }
    cout<<sum<<endl;
    return 0;
}
