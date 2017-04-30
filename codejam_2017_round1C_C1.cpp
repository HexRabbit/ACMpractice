#include <iostream>
#include <algorithm>
#include <cstdio>
#include <utility>
using namespace std;
double core[51];
int main()
{
	int C,a=1;
	cin >> C;
	while(C--)
	{
		int num,req;
		double tra;
		cin >> num >> req >> tra;
		for(int i=0; i<num; ++i)
		{
			cin >> core[i];
		}
		core[num]=1;
		sort(core,core+num);
		for(int i=0; i<num; ++i)
		{
			if((i+1)*(core[i+1]-core[i])<=tra)
			{
				tra-=(i+1)*(core[i+1]-core[i]);
				for(int j=0; j<i+1; ++j)
				{
					core[j]=core[i+1];
				}
			}
			else
			{
				for(int j=0; j<i+1; ++j)
				{
					core[j]+=tra/(i+1);
				}
				break;
			}
		}
		double ans=1;
		for(int i=0;i<num;i++)ans*=core[i];
		printf("Case #%d: %.6lf\n",a,ans);
		a++;
	}
}
