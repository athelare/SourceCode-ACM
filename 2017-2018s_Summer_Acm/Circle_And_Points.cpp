#include<iostream>
#include<cmath>
using namespace std;
double x[303],y[303],cx,cy;
int N,MaxIn;
inline double distance(double& x1,double& y1,double& x2,double& y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
inline void getcircle(double x1,double y1,double x2,double y2){
    double tha1 = atan2(y2-y1,x2-x1);
    double d = sqrt(1 - distance(x1,y1,x2,y2)*distance(x1,y1,x2,y2)/4);
    double mx = (x1+x2)/2,my = (y1+y2)/2;
    cx = mx + d * sin(tha1);
    cy = my - d * cos(tha1);
}
void CountNum(){
    int co = 0;
    for(int i=0;i<N;++i){
        if(distance(cx,cy,x[i],y[i])<=1.0 + 1e-5)co++;
    }
    if(co>MaxIn)MaxIn = co;
}
int main()
{
    std::ios::sync_with_stdio(false);
    while(cin>>N && N){
        MaxIn = 1;
        for(int i=0;i<N;++i)cin>>x[i]>>y[i];
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                if(i == j)continue;
                if(distance(x[i],y[i],x[j],y[j])<2.0){
                    getcircle(x[i],y[i],x[j],y[j]);
                    CountNum();
                }
            }
        }
        cout<<MaxIn<<endl;
    }
    return 0;
}