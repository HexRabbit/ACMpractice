#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdio>
using namespace std;
int pt[105];
vector<pair<int,int>> route;
int main()
{
	int n,aa=1;
	while(cin >> n && n!=0)
	{
		int start;
		cin >> start;
		route.resize(0);
		for(int i=0,a,b;cin >> a >> b && a!=0;i++){route.push_back(make_pair(a,b));}
		memset(pt,-1,sizeof(pt));
		pt[start]=0;
		int mx=-1;
		int pmax=start;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<route.size();j++)
			{
				if(pt[route[j].first]!=-1)
				{
					pt[route[j].second]=max(pt[route[j].first]+1,pt[route[j].second]);
					if(mx<=pt[route[j].second]) 
					{
						if(mx==pt[route[j].second]) pmax=min(pmax,route[j].second);
						else pmax=route[j].second;
						mx=pt[route[j].second];
					}
				}
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",aa,start,mx,pmax);
		aa++;
	}
}
