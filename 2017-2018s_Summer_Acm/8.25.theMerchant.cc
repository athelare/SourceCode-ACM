#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#define mem(x,v) memset(x,v,sizeof(x)) 
#define rep(i,a,b)  for (int i = a; i < b; i++)
#define per(i,a,b)  for (int i = a; i > b; i--)
using namespace std;
typedef long long LL;
const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;
const int N = 1e5+10;
vector<int>g[N];
int f[N][20],Max[N][20],Min[N][20],Up[N][20],Down[N][20];
int dep[N],a[N],n;
void dfs(int u, int fa){
	for (int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (v == fa) continue;
		f[v][0] = u;
		dep[v] = dep[u] + 1;
		Max[v][0] = max(a[v],a[u]);
		Min[v][0] = min(a[v],a[u]);
		Up[v][0] = max(0,a[u] - a[v]);
		Down[v][0] = max(0,a[v] - a[u]);
		dfs(v,u);
	}
	return;
}
 
 
void init(){
	mem(f,-1);
	dep[1] = 1;
	dfs(1,0);
	for (int j = 1; j < 20; j++)
		for (int i = 1; i <= n; i++)
			if (~f[i][j-1]){
				int a,b,k = f[i][j-1];
				f[i][j] = f[k][j-1];
				Max[i][j] = max(Max[i][j-1],Max[k][j-1]);
				Min[i][j] = min(Min[i][j-1],Min[k][j-1]);
				a = max(0,Max[k][j-1] - Min[i][j-1]);
				b = max(Up[i][j-1],Up[k][j-1]);
				Up[i][j] = max(a,b);
				a = max(0,Max[i][j-1]-Min[k][j-1]);
				b = max(Down[i][j-1],Down[k][j-1]);
				Down[i][j] = max(a,b);
			}
	return;
}
int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x,y);
	per(i,19,-1)
	if (dep[f[x][i]] >= dep[y]) x = f[x][i];
	if (x == y) return x;
	per(i,19,-1)
	if (f[x][i] != f[y][i]){
		x = f[x][i];
		y = f[y][i];
	}
	return f[x][0];
}
int Query_up(int x, int deep, int &min_val){
	int ans = 0;
	per(i,19,-1)
	if (deep & (1 << i)){
		ans = max(ans,Up[x][i]);
		ans = max(ans,Max[x][i] - min_val);
		min_val = min(min_val,Min[x][i]);
		x = f[x][i];
	}
	return ans;
}
int Query_down(int x, int deep, int &max_val){
	int ans = 0;
	per(i,19,-1)
	if (deep & (1 << i)){
		ans = max(ans,Down[x][i]);
		ans = max(ans,max_val-Min[x][i]);
		max_val = max(max_val,Max[x][i]);
		x = f[x][i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1)
	scanf("%d",&a[i]);
	rep(i,0,n+1)
	g[i].clear();
	rep(i,1,n){
		int x=i,y=i+1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	init(); int m;
	{
		int x,y,z;
		x=1,y=n;
		z = lca(x,y);
		int max_val = 0, min_val = INF,a,b;
		a = Query_up(x,dep[x] - dep[z],min_val);
		b = Query_down(y,dep[y] - dep[z],max_val);
		z = max(max(0,max_val - min_val),max(a,b));
		printf("%d\n",z);
	}
	return 0;
}
