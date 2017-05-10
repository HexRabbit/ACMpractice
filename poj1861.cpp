#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Line
{
	int a,b,c;
};
Line line[20000];
vector<Line> ans;
int dset[1005];
bool cmp(Line a,Line b) {return a.c < b.c;}
int findrt(int p)
{
	if(p == dset[p]) return p;
	else return dset[p] = findrt(dset[p]);
}
void merge(Line l){ dset[findrt(l.a)] = findrt(l.b);}
int main()
{
	int num,pr;
	while(scanf("%d%d",&num,&pr)==2)
	{
		ans.clear();
		memset(line,0,sizeof(line));
		memset(dset,0,sizeof(dset));
		for(int i=0; i<pr; ++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			line[i]={a,b,c};
		}
		sort(line,line+pr,cmp);
		for(int i=0; i<num; ++i)
		{
			dset[i]=i;
		}
		for(int i=0,j=0; i<num-1 && j<pr; ++i,++j)
		{
			while(findrt(line[j].a) == findrt(line[j].b)) j++;
			merge(line[j]);
			ans.push_back(line[j]);
		}
		cout << ans[num-2].c << endl;
		cout << num-1 << endl;
		for(int i=0; i<num-1; ++i)
		{
			printf("%d %d\n",ans[i].a,ans[i].b);
		}

	}
	return 0;
}
