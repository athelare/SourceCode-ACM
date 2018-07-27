#include<bits/stdc++.h>
#define MXN 10002
#define INF 10000
using namespace std;
typedef pair<double,double> P;

P A[MXN];
int N;

bool compare_y(P a,P b){
	return a.second<b.second;
}
double ClosestDistance(P *a,int n){
	if(n<=1)return INF;
	int m = n/2;
	double x = a[m].first;
	double d = min(ClosestDistance(a,m),ClosestDistance(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);

	std::vector<P> v;
	for(int i=0;i<n;++i){
		if(abs(a[i].first - x)>=d)continue;
		for(size_t j=0;j<v.size();++j){
			double dx = a[i].first - v[j].first;
			double dy = a[i].second - v[j].second;
			d = min(d,sqrt(dx*dx+dy*dy));
		}
		v.push_back(a[i]);
	}
	return d;
}

int main()
{
	while(cin>>N){
		if(!N)break;
		for(int i=0;i<N;++i){
			scanf("%lf%lf",&A[i].first,&A[i].second);
		}
		sort(A,A+N);
		double d = ClosestDistance(A,N);
		if(d>=INF){
			printf("INFINITY\n");
		}else{
			printf("%.4f\n",d);
		}
	}
	return 0;
}
