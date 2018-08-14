#include<bits/stdc++.h>
using namespace std;
int N,target;
double x[100005],y[100005];
#define random (rand()%N)
inline double Determinant(
    double a11,double a12,double a13,
    double a21,double a22,double a23,
    double a31,double a32,double a33){
        return a11*a22*a33+a12*a23*a31+a21*a32*a13 
            -a13*a22*a31-a12*a21*a33-a11*a32*a23;
    }
struct Circle{
    double cx,cy,R;
};
void Construct(Circle& cl,int a,int b,int c){
    cl.cx = 0.5*Determinant(
        1,x[a]*x[a]+y[a]*y[a],y[a],
        1,x[b]*x[b]+y[b]*y[b],y[b],
        1,x[c]*x[c]+y[c]*y[c],y[c]
    )/Determinant(
        1,x[a],y[a],
        1,x[b],y[b],
        1,x[c],y[c]
    );
    cl.cy = 0.5*Determinant(
        1,x[a],x[a]*x[a]+y[a]*y[a],
        1,x[b],x[b]*x[b]+y[b]*y[b],
        1,x[c],x[c]*x[c]+y[c]*y[c]
    )/Determinant(
        1,x[a],y[a],
        1,x[b],y[b],
        1,x[c],y[c]
    );
    double  ca = sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])),
            cb = sqrt((x[a]-x[c])*(x[a]-x[c])+(y[a]-y[c])*(y[a]-y[c])),
            cc = sqrt((x[c]-x[b])*(x[c]-x[b])+(y[c]-y[b])*(y[c]-y[b])),
            p = (ca+cb+cc)/2,
            S = sqrt(p*(p-ca)*(p-cb)*(p-cc));
    cl.R = ca*cb*cc/(4*S);
}
bool ok(Circle &cl){
    if(cl.R>1e9)return false;
    int count = 0;
    double eps;
    for(int i=0;i<=N;++i){
        eps = abs(cl.R - sqrt((x[i]-cl.cx)*(x[i]-cl.cx)+(y[i]-cl.cy)*(y[i]-cl.cy)));
        if(eps < 1e-6)count++;
    }
    return count>=target;
}
//1 3 5 6
void solve(){
    int a,b,c;
    Circle circle;
    while(true){
        a=random;b=random,c=random;
        if(a == b || a == c || b == c)continue;
        if(x[a] == x[b] && x[b] == x[c])continue;
        if(y[a] == y[b] && y[b] == y[c])continue;
        Construct(circle,a,b,c);
        if(ok(circle)){
            printf("%f %f %f\n",circle.cx,circle.cy,circle.R);
            return;
        }
    }
}
int main()
{
    srand(time(NULL));
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        target = (int)ceil((double)N/2);
        for(int i=0;i<N;++i)scanf("%lf%lf",&x[i],&y[i]);
        if(N<=4){
            cout<<(x[0]+x[1])/2<<' '<<(y[0]+y[1])/2<<' '<<sqrt((x[1]-x[0])*(x[1]-x[0])+(y[1]-y[0])*(y[1]-y[0]))/2<<endl;
        }else
            solve();
    }
    return 0;
}
