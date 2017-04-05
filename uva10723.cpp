#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <iostream>
using namespace std;
int cmap[40][40];
string s1,s2;
vector<char> v1,v2;
map<int,int> lcnt;
void solve(int,int,int);
int main()
{
	int cnt,a=0;
	string temp;
	cin >> cnt;
	while(cnt--)
	{
		v1.resize(0);
		v2.resize(0);
		cin >> temp;
		for(int i=0; i<temp.length(); ++i)
		{
			v1.push_back(temp[i]);
		}
		cin >> temp;
		for(int i=0; i<temp.length(); ++i)
		{
			v2.push_back(temp[i]);
		}
		for(int i=0; i<40; ++i)
		{
			for(int j=0; j<40; ++j)
			{
				cmap[i][j]=0;
			}
		}
		for(int i=0; i<v1.size(); ++i)
		{
			for(int j=0; j<v2.size(); ++j)
			{
				if(v1[i]==v2[j]) cmap[i][j]=1;
			}
		}
		lcnt.clear();
		solve(0,0,1);
		int mx=0xFFFFFFFF;
		int cmx=0;
		for(map<int,int>::iterator it=lcnt.begin(); it!=lcnt.end(); ++it)
		{
			if(mx > it->first && it->first > 0)
			{
				mx=it->first;
				cmx=it->second;
			}
		}
		printf("Case #%d: %d %d\n",a,mx,cmx);
		a++;
	}
}

void solve(int i,int j,int cnt)
{
	if(i==v1.size()-1 && j==v2.size()-1) {
		++lcnt[cnt];
		return;
	}
	else if(i==v1.size()-1) return solve(i,j+1,cnt+1);
	else if(j==v2.size()-1) return solve(i+1,j,cnt+1);
	else
	{
		if(cmap[i][j]==1) return solve(i+1,j+1,cnt+1);
		else
		{
			solve(i+1,j,cnt+1);
			solve(i,j+1,cnt+1);
			return;
		}
	}
}
