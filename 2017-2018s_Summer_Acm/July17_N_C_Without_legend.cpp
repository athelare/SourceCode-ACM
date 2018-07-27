#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int sequ[3005];
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		scanf("%d",&sequ[i]);
		sequ[i]-=i;
	}
	int max = 0;
	for(int i=0;i<n;++i){
		if(sequ[i]>max)max = sequ[i];
	}
	int ans = 0;
	for(int i=0;i<n;++i){
		ans+=max-sequ[i];
	}
	printf("%d\n",ans);
	return 0;
}
