
#include<cstdio>
using namespace std;
int main()
{
    int T,times(0);
    int n;
    int a[20];
    scanf("%d", &T);
    while(times++<T){
        scanf("%d", &n);
        int max(0),sum(0),ans;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            sum += a[i];
            if (a[i] > max)
                max = a[i];
        }
        
        ans = sum / 2;
        
        printf("Case #%d: %d\n", times,ans);
    }
    return 0;
}