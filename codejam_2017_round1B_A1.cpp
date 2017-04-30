#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int horse[1005][2];
int main()
{
	int C,a=1;
	cin >> C;
	while(C--)
	{
		int goal,n;
		cin >> goal >> n;
		for(int i=0; i<n; ++i)
		{
			cin >> horse[i][0] >> horse[i][1];
		}
		double slow=(double)(goal-horse[0][0])/(double)horse[0][1];
		for(int i=0; i<n; ++i)
		{
			slow=max(slow,(double)(goal-horse[i][0])/(double)horse[i][1]);
		}
		printf("Case #%d: %.6lf\n",a,goal/slow);
		a++;
	}
	return 0;
}
