#include<cstdio>
#include<cstring>

int main()
{
    int qA,qB,T,nums[11],i;
    bool flg;
    scanf("%d",&T);
    while(T--){
        qA=qB=0;
        flg = true;
        for(i=0;i<10;++i){
            scanf("%d",&nums[i]);
        }
        for(i=0;i<10;++i){
            if(qA == qB){
                qA = nums[i];
            }else{
                if(nums[i] - qA >0 && nums[i] - qA < nums[i] - qB){
                    qA = nums[i];
                }else{
                    if(nums[i] - qB < 0 ){
                        flg = false;
                        break;
                    }
                    qB = nums[i];
                }
            }
        }
        puts(flg?"YES":"NO");
    }
    return 0;
}