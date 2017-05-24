#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;
int n,m,k;
bool R[105][105];
bool check[105];
int match[105];
bool dfs(int u);
int main()
{
	while(scanf("%d%d%d",&n,&m,&k) == 3)
	{
		int ans=0;
		memset(R,false,sizeof(R));
		for(int i=0;i<k;i++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(!b || !c) continue;
			R[b][c] = true;
		}
		memset(match,-1,sizeof(match));
		for(int i=0;i<m;++i) {
			memset(check,0,sizeof(check));
			if(dfs(i)) ans++;
		}
		printf("%d\n", ans);
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
