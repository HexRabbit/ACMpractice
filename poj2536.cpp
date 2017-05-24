#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
int n,m,s,v;
double x[105],y[105],R[105][105];
bool check[105];
int match[105];
bool dfs(int u);
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&s,&v)==4)
	{
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf",&x[i],&y[i]);
		}
		for (int i = 0; i < m; ++i)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			for (int j = 0; j < n; ++j)
			{
				double d = sqrt(pow(a-x[j],2)+pow(b-y[j],2));	
				if(d/v <= s) R[i][j] = 1;
				else R[i][j] = 0;
			}
		}
		memset(match,-1,sizeof(match));
		int ans=0;
		for(int i=0;i<m;++i) {
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		printf("%d\n", n-ans);
	}

}


bool dfs(int u)
{
	for(int i=0;i<n;i++) {
		if(R[i][u] && !check[i]) {
			check[i]=1;
			if(match[i]==-1||dfs(match[i])) {
				match[i]=u;
				return true;
			}
		}
	}
	return false;
}

