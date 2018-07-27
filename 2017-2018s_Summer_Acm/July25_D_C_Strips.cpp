#include<queue>
#include<cstdio>
#include<math.h>
using namespace std;
int main()
{
    priority_queue<double> heap;
    int n,tmp;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&tmp);
        heap.push(tmp);
    }
    double t1,t2;
    while(heap.size()>1){
        t1 = heap.top();heap.pop();
        t2 = heap.top();heap.pop();
        heap.push(2*sqrt(t1*t2));
    }
    printf("%.3f\n",heap.top());
    return 0;
}