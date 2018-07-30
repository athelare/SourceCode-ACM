//AC
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int numlist[]={1,2,3,4,5,6,7,8,9,10};
int nums[13],adde1[13],adder2[13],*a,*b;
int main()
{
    int l,sum;
    while(cin>>l>>sum){
        for(int i=0;i<l;++i){
            nums[i] = numlist[i];
        }
        a = adde1,b=adder2;
        do{
            for(int i=0;i<l;++i){
                 a[i] = nums[i];
            }
            for(int i=l-1;i>0;--i){
                for(int j=0;j<i;++j){
                    b[j] = a[j] + a[j+1];
                }
                swap(a,b);
            }
            if(a[0] == sum){
                for(int i=0;i<l;++i){
                    printf("%d%c",nums[i],i==l-1?'\n':' ' );
                } 
                return 0;
            }
        }while(next_permutation(nums,nums+l));
    }
}