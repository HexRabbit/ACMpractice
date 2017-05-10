#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
struct Line
{
	int a,b;
	double c;
};
Line line[750*750/2];
int x[800],y[800];
vector<Line> ans;
int dset[800];
bool cmp(Line a,Line b) {return a.c < b.c;}
int findrt(int p) {return p == dset[p] ? p : dset[p] = findrt(dset[p]); }
void merge(Line l) {dset[findrt(l.a)] = findrt(l.b);}

int main()
{
	int C;
	scanf("%d",&C);
	while(C--)
	{
		int N,M;
		ans.clear();
		memset(line,0,sizeof(line));
		memset(dset,0,sizeof(dset));
		int pr=0;

		scanf("%d",&N);
		for(int i=0; i<N; ++i) {
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=0; i<N; ++i)
			for(int j=i+1; j<N; ++j)
				line[pr++]={i,j,sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2))};

		for(int i=0; i<N; ++i) dset[i]=i;
		scanf("%d",&M);
		for(int i=0; i<M; ++i) {
			int a,b;
			scanf("%d%d",&a,&b);
			merge({a-1,b-1,0});
		}

		sort(line,line+pr,cmp);

		for(int j=0; j<pr; ++j) {
			if(findrt(line[j].a) == findrt(line[j].b)) continue;
			merge(line[j]);
			ans.push_back(line[j]);
		}

		for(int i=0; i<ans.size(); ++i) {
			printf("%d %d\n",ans[i].a+1,ans[i].b+1);
		}
		if(!ans.size()) printf("No new highways need\n");
		if(C) printf("\n");
	}
	return 0;
}
