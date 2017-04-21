#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mmax=2000+5;
const int nmax=1000+5;
int a[mmax],b[mmax],w[mmax],star[nmax];
bool solve(int,int);
int main()
{
	int C;
	cin >> C;
	while(C--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=0; i<m; ++i)
		{
			cin >> a[i] >> b[i] >> w[i];
		}
		fill(star,star+n,0x4fffffff);
		if(solve(n,m))
		{
			cout << "possible" << endl;
		}
		else
		{
			cout << "not possible" << endl;
		}
	}
	return 0;
}

bool solve(int n,int m)
{
	int cnt=0;
	for(int i=0;i<n+2;i++)
	{
		int check=0;
		for(int j=0; j<m; ++j)
		{
			if(star[a[j]]+w[j]<star[b[j]])
			{
				check=1;
				star[b[j]]=star[a[j]]+w[j];
			}
		}
		if(check) cnt++;
	}
	return cnt>n;
}
