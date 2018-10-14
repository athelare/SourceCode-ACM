#include<stdio.h>
int main()
{
  long long MaxSum,curSum,nums[10005];
  int i,n,mxl,mxr,cxl;
  scanf("%d",&n);
  curSum = 0;
  MaxSum = -1;
  i = 0;
  cxl=mxl=0,mxr=n-1;
  
  while(i<n){
    scanf("%lld",&nums[i]);
    curSum+=nums[i];
    if(curSum < 0){
      curSum = 0;
      cxl = ++i;
      continue;
    }
    if(curSum>MaxSum){
      MaxSum = curSum;
      mxl = cxl;
      mxr = i;
    }
    ++i;
  }
    printf("%lld %lld %lld\n",MaxSum<0?0:MaxSum,nums[mxl],nums[mxr]);


  return 0;
}