#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
struct Line{
	int a,b;
	double len;
};
int dset[5050];
Line line[500000];
int x[5050],y[5050];

int findrt(int p) { return (dset[p] == p ? p : dset[p] = findrt(dset[p])); }
void merge(int a, int b) { dset[findrt(a)] = findrt(b); }
bool cmp(Line a,Line b) { return a.len < b.len; }
int main()
{
	int C;
	cin >> C;
	while(C--)
	{
		int S,P,k=0;
		cin >> S >> P;
		for (int i = 0; i < P; ++i)
		{
			cin >> x[i] >> y[i];
		}
		for (int i = 0; i < P; ++i)
		{
			for (int j = i+1; j < P; ++j)
			{
				line[k++] = {i,j,sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))};
			}
		}
		sort(line,line+k,cmp);
		for (int i = 0; i < P; ++i)
		{
			dset[i]=i;
		}
		double mx=0;
		for (int i=0,j=0; j < P-1-S+1 && i < k; i++,j++)
		{
			while(findrt(line[i].a) == findrt(line[i].b)) i++;
			merge(line[i].a,line[i].b);
			mx=line[i].len;
		}
		printf("%.2f\n", mx);
	}
	return 0;
}


