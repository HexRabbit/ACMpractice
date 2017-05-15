#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
typedef int Graph[300][300];
const int INF = 2e9;
Graph R,C;
int num;
const int jump=150;
int bfn[300],flow[300],check[300];
int BFS(int,int);
int main()
{
	while(scanf("%d",&num)==1)
	{
		int m,s,t;
		memset(R,0,sizeof(R));
		memset(C,0,sizeof(C));
		for(int i=1; i<=num; ++i)
		{
			int c;
			scanf("%d",&c);
			R[i][i+jump]=c;
			R[i+jump][i]=c;
			C[i+jump][i]=c;
			C[i][i+jump]=c;
		}
		scanf("%d",&m);
		for(int i=0; i<m; ++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			R[a+jump][b]=c;
			C[a+jump][b]=c;
			C[b][a+jump]=c;
		}
		scanf("%d%d",&s,&t);
		for(int i=0; i<s; ++i)
		{
			int b;
			scanf("%d",&b);
		printf("ADD");
			R[0][b] = INF;
			C[0][b] = INF;
			C[b][0] = INF;
		}
		printf("SADASD");
		for(int i=0; i<t; ++i)
		{
			int bb;
			scanf("%d",&bb);
			R[bb+jump][280] = INF;
			C[bb+jump][280] = INF;
			C[280][bb+jump] = INF;
		}
		printf("sdsd");
		bfn[0]=-1;
		int f,df;
		for(f=0; (df = BFS(0,280)); f+=df) {
			for(int i=t;~bfn[i];i=bfn[i]) {
				int j=bfn[i];
				R[j][i] -= df;
				R[i][j] = C[i][j] - R[j][i];
			}
		}
		cout << f <<endl;
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
		for(int j=0; j<=280; ++j)
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
