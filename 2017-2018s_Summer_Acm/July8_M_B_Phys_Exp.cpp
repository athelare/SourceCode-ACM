#include<cstdio>
#include<math.h>
#include<algorithm>
#include<iostream>

int N, H, R, T;
double ans[105];
double calc(int T)
{
    if (T < 0 )return H;
    double eacht,loopt, realt;
    eacht = sqrt((2.0 * H / 10.0));
    int k = (int)(T/eacht);
    if(k%2 == 0){
        double d = T - k*eacht;
        return H - 10.0*d*d/2;
    }
    else{
        double d = k*eacht +eacht - T;
        return H - 10.0*d*d/2;
    }
}

void solve()
{
   int i(0);

   std::cin >> N >> H >> R >> T;
   for (i = 0; i < N;++i){
       ans[i] = calc(T - i);
   }
   std::sort(ans, ans + N);
   i = 0;
   while (i < N)
   {
       printf("%.2lf", ans[i] + 2 * R * i / 100.0);

       if (++i == N)
           printf(" ");
       else
       {
           printf("\n");
       }
   }
}
int main()
{
    int Times;
    std::cin >> Times;
    while(Times--){
        solve();
    }

    return 0;
}
