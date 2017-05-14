#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int C[105][105],R[105][105];
int dfn[105];
bool check[105];
int flow[105];
int num;
int DFS(int,int);
int main()
{
	int aa=1;
	while(scanf("%d",&num) && num)
	{
		int s,t,cnt;
		scanf("%d%d%d",&s,&t,&cnt);
		memset(C,0,sizeof(C));
		memset(R,0,sizeof(R));
		for(int i=0; i<cnt; ++i) {
			int a,b,c;
			cin >> a >> b >> c;
			C[a][b] += c;
			C[b][a] += c;
			R[b][a] += c;
			R[a][b] += c;
		}
		dfn[s]=-1;
		int f,df;
		for(f=0; (df = DFS(s,t)); f+=df) {
			for(int i=t;~dfn[i];i=dfn[i]) {
				int j=dfn[i];
				R[j][i] -= df;
				R[i][j] = C[i][j] - R[j][i];
			}
		}
		if(aa>1) printf("\n");
		printf("Network %d\nThe bandwidth is %d.\n",aa,f);
		aa++;
	}
	return 0;
}


int DFS(int s,int t)
{
	stack<int> st;
	memset(check,false,sizeof(check));
	memset(flow,7,sizeof(flow));
	st.push(s);
	check[s]=true;
	while(!st.empty())
	{
		int i=st.top();st.pop();
		for(int j=1; j<=num; ++j)
		{
			if(!check[j] && R[i][j] > 0)
			{
				st.push(j);
				check[j] = true;
				dfn[j] = i;
				flow[j] = min(flow[i],R[i][j]);
				if(j == t) return flow[t];
			}
		}
	}
	return 0;
}
