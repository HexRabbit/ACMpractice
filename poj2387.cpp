#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int tmax=2000+5;
const int nmax=1000+5;
int a[tmax],b[tmax],w[tmax],star[nmax];
void solve(int,int);
int main()
{
	int t,n;
	while(cin >> t >> n)
	{
		for(int i=0; i<t; ++i)
		{
			cin >> a[i] >> b[i] >> w[i];
		}
		fill(star,star+n,0x4fffffff);
		star[n]=0;
		solve(n,t);
		cout << star[1] << endl;
	}
	return 0;
}

void solve(int n,int t)
{
	for(int i=0;i<n-1;i++)
	{
		int check=0;
		for(int j=0; j<t; ++j)
		{
			if(star[a[j]]+w[j]<star[b[j]])
			{
				star[b[j]]=star[a[j]]+w[j];
				check=1;
			}
			if(star[b[j]]+w[j]<star[a[j]])
			{
				star[a[j]]=star[b[j]]+w[j];
				check=1;
			}
		}
		if(!check) break;
	}
}
