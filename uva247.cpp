#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <cstring>
#include <string>
using namespace std;
const int MAX=30;
stack<int> st;
int call[MAX][MAX];
map<string,int> name;
map<int,string> rname;
int check[MAX],dfn[MAX],low[MAX];
int d[MAX],la[MAX];
int idx=0,n,m,aa=1;
void DFS(int);
void rDFS(int);
int main()
{
	while(cin >> n >> m && n!=0)
	{
		memset(call,0,sizeof(call));
		memset(check,0,sizeof(check));
		memset(dfn,-1,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(d,0,sizeof(d));
		memset(la,0,sizeof(la));
		name.clear();
		rname.clear();
		while(!st.empty()) st.pop();
		idx=0;
		for(int i=0,d=0; i<m; ++i)
		{
			string a,b;
			cin >> a >> b;
			if(name.find(a)==name.end()) name[a]=d++;
			if(name.find(b)==name.end()) name[b]=d++;
			rname[name[a]]=a;
			rname[name[b]]=b;
			call[name[a]][name[b]]=1;
		}
		DFS(0);
		for(int i=0; i<n; ++i)
		{
			if(!~dfn[i]) DFS(i);
		}
		cout << "Calling circles for data set " << aa << ':' << endl;
		aa++;
		for(int i;!st.empty();st.pop())
		{
			i=st.top();
			if(la[i]) continue;
			rDFS(i);
			for(int j=0,k=0;j<n;j++)
			{
				if(d[j])
				{
					if(k>0) cout << ", ";
					cout << rname[j];
					k++;
				}
			}
			puts("");
			memset(d,0,sizeof(d));
		}
		/*
			 for(int i=0; i<n; ++i)
			 {
			 cout << low[i] << endl;
			 }
			 for(int i=0; i<n; ++i)
			 {
			 if(low[i]==-1) continue;
			 int a=low[i],cnt=0;
			 for(int j=0; j<n; ++j)
			 {
			 if(low[j]==a)
			 {
			 low[j]=-1;
			 if(cnt>0) printf(", ");
			 cout << rname[j];
			 cnt++;
			 }
			 }
			 puts("");
			 }
			 */
	}
	return 0;
}
/*
	 void DFS(int now)
	 {
	 dfn[now]=low[now]=idx++;
	 for(int i=0; i<n; ++i)
	 {
	 if(call[now][i])
	 {
	 if(!~dfn[i]) DFS(i);
	 if(!check[i])
	 {
	 low[now]=min(low[now],low[i]);
	 }
	 }
	 }
	 check[i]=1;
	 }
	 */
void DFS(int now)
{
	dfn[now]=1;
	for(int i=0; i<n; ++i)
	{
		if(call[now][i])
		{
			if(!~dfn[i]) DFS(i);
		}
	}
	st.push(now);
}

void rDFS(int now)
{
	d[now]=la[now]=1;
	for(int i=0; i<n; ++i)
	{
		if(call[i][now] && !la[i])
		{
			if(!d[i]) rDFS(i);
		}
	}
}
