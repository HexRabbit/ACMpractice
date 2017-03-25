#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
struct Case
{
	int num;
	double price;
};
int main(int argc, char const *argv[])
{
	char a;
	int plot;
	double base;
	struct Case cases[20];
	int total;
	int YYY=1;
	vector<double> v;
	v.resize(101);
	while(cin >> base)
	{
		printf("Case %d:\n", YYY);
		cin >> total;
		for(int i=0;i<total;i++)
		{
			cin >> cases[i].num >> cases[i].price;
		}
		for (int i = 0; i < 101; ++i)
		{
			v.at(i)=i*base;
		}
		while(scanf("%d%c",&plot,&a))
		{
			for (int i = 0; i < total; ++i)
			{
				for (int j = cases[i].num; j <= 100; ++j)
				{
					v[j] = min(v[j],v[j-cases[i].num] + cases[i].price);
					for (int k = j; k > 0; --k)
					{
						v[k-1]=min(v[k],v[k-1]);
					}
				}
				
			}
			printf("Buy %d for $%.2f\n", plot, v[plot]);
			if(a == '\n') break;
		}
		YYY++;
	}
	return 0;
}
