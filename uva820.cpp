#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int C[105][105],R[105][105];
int bfn[105];
bool check[105];
int flow[105];
int num;
int BFS(int,int);
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
		bfn[s]=-1;
		int f,df;
		for(f=0; (df = BFS(s,t)); f+=df) {
			for(int i=t;~bfn[i];i=bfn[i]) {
				int j=bfn[i];
				R[j][i] -= df;
				R[i][j] = C[i][j] - R[j][i];
			}
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",aa,f);
		aa++;
	}
	return 0;
}


int BFS(int s,int t)
{
	queue<int> qu;
	memset(check,false,sizeof(check));
	memset(flow,7,sizeof(flow));
	qu.push(s);
	check[s]=true;
	while(!qu.empty())
	{
		int i=qu.front();qu.pop();
		for(int j=1; j<=num; ++j)
		{
			if(!check[j] && R[i][j] > 0 && i!=j)
			{
				qu.push(j);
				check[j] = true;
				bfn[j] = i;
				flow[j] = min(flow[i],R[i][j]);
				if(j == t) return flow[t];
			}
		}
	}
	return 0;
}
