#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
int C[50][50],R[50][50];
int bfn[50];
bool check[50];
int flow[50];
int BFS(int,int);
int trans(char);
int main()
{
	string str;
	while(cin >> str && str!="ENDOFINPUT")
	{
		memset(C,0,sizeof(C));
		memset(R,0,sizeof(R));
		int per;
		scanf("%d",&per);
		for (int i = 1; i <= per; ++i)
		{
			cin >> str;
			int a=trans(str[0]),b=trans(str[1]);
			for (int j = a; j <= b; ++j)
			{
				R[i][j] = 1;
				R[j][i] = 1;
				C[i][j] = 1;
				C[j][i] = 1;
			}
			C[0][i] = 1;
			R[0][i] = 1;
		}
		for (int i = 21; i <= 25; ++i)
		{
			int a;
			cin >> a; 
			C[i][26] = a;
			R[i][26] = a;
		}
		cin >> str;	
		int f,df;
		int s=0,t=26;
		bfn[s]=-1;
		for(f=0; (df = BFS(s,t)); f+=df) {
			for(int i=t;~bfn[i];i=bfn[i]) {
				int j=bfn[i];
				R[j][i] -= df;
				R[i][j] = C[j][i] - R[j][i];
			}
		}
		if(f==per) cout << "T-shirts rock!" << endl;
		else cout << "I'd rather not wear a shirt anyway..." << endl;

	}
	return 0;
}
int trans(char c)
{
	switch(c){
		case 'S': return 21;
		case 'M': return 22;
		case 'L': return 23;
		case 'X': return 24;
		case 'T': return 25;
	}
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
		for(int j=1; j<=26; ++j)
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
