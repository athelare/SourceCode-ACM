#include<iostream>
using namespace std;
struct Rect
{
    int n, d;
    bool in(int x,int y){
        return 
            y <= x + d &&
            y >= x - d &&
            x + y >= d &&
            x + y <= n*2 - d;
   }
};
int main()
{
    int m,x,y;
    Rect r;
    cin >> r.n >> r.d >> m;
    while(m--){
        cin >> x >> y;
        puts(r.in(x, y) ? "YES" : "NO");
    }
    return 0;
}