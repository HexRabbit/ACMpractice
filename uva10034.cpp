#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Line
{
	int a,b;
	double len;
};
pair<double,double> frek[105];
int dset[105];
Line line[10000];
double ans;
bool Union(Line);
bool compare(Line,Line);
int findrt(int);
int main()
{
	int C,a=0;
	cin >> C;
	while(C--)
	{
		int N;
		ans=0;
		cin >> N;
		for(int i=0; i<N; ++i)
		{
			cin >> frek[i].first >> frek[i].second;
		}
		int cnt=0;
		for(int i=0; i<N; ++i)
		{
			for(int j=i+1; j<N; ++j)
			{
				line[cnt++] = {i,j,sqrt(pow(frek[i].first-frek[j].first,2)+pow(frek[i].second-frek[j].second,2))};
			}
		}
		sort(line,line+cnt,compare);
		for(int i=0; i<N; ++i)
		{
			dset[i]=i;
		}
		for(int i=0,j=0; j != N-1; ++i)
		{
			if(Union(line[i])) j++;
		}
		if(a) printf("\n");
		printf("%.2f\n",ans);
		a=1;
	}
}

bool compare(Line a,Line b){return (a.len<b.len);}

bool Union(Line ln)
{
	int a = findrt(ln.a);
	int b = findrt(ln.b);
	if(a != b)
	{
		dset[a]=b;
		ans += ln.len;
		return true;
	}
	return false;
}

int findrt(int p)
{
	if(dset[p] == p) return p;
	else return findrt(dset[p]);
}
