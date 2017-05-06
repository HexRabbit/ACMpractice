#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dfn[105],low[105],art[105];
vector<int> line[105];
int idx=1,cnt,num,c;
void DFS(int,int);
int main()
{
	while(cin >> num && num!=0)
	{
		int a,b;
		char t;
		memset(line,0,sizeof(line));
		memset(art,0,sizeof(art));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		while(cin >> a && a!=0)
		{
			while(scanf("%d%c",&b,&t))
			{
				line[a].push_back(b);
				line[b].push_back(a);
				if(t=='\n') break;
			}
		}
		c=0;
		cnt=0;
		idx=1;
		DFS(1,0);
		for(int i=1; i<=num; ++i)
		{
			if(art[i]) cnt++;
		}
		cout << cnt+(c>1?1:0) << endl;
	}
}

void DFS(int now,int prev)
{
	dfn[now]=low[now]=idx++;
	for(int i : line[now])
	{
		if(i != prev)
		{
			if(!dfn[i])
			{
				if(now==1)c++;
				DFS(i,now);
				low[now]=min(low[now],low[i]);
				if(dfn[now]<=low[i] && now != 1) art[now]=1;
			}
			else low[now]=min(low[now],dfn[i]);
		}
	}
}
