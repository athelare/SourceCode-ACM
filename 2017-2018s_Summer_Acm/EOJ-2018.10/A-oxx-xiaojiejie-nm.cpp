#include<iostream>
#include<cstdio>
int W, H, p,count=0;
int positions[105][105];
bool fill(int y,int x,int w, int h)
{
    if((w*h)%p != 0)
        return false;
    if(w<p && h%p != 0)
        return false;
    if(h<p && w%p != 0)
        return false;
    if(w>=p){
        int m = w / p;
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w - w % p;++j){
                positions[y + i][x + j] = count + m * i + j / p + 1;
            }
        }
        count += m * h;
        if (w % p == 0)
            return true;
        return fill(y, x + w - w % p, w % p, h);
    }else if(h>=p){
        int m = h / p;
        for (int i = 0; i <h- h%p; ++i)
        {
            for (int j = 0; j < w;++j){
                positions[y + i][x + j] = count + m * j + i / p + 1;
            }
        }
        count += m * w;
        if (h % p == 0)
            return true;
        return fill(y+h-h%p, x, w, h%p);
    }
}
int main()
{
    scanf("%d%d%d", &H, &W, &p);
    if(fill(0,0,W,H)){
        printf("Yes\n");
        for (int i = 0; i < H;++i){
            for (int j = 0; j < W;++j){
                printf("%d%c", positions[i][j], j == W - 1 ? '\n' : ' ');
            }
        }
    }else{
        printf("No\n");
    }
    return 0;
}