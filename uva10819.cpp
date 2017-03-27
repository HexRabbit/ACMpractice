#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int total, C, price, value, a=0;
	vector<int> dp;
	while(scanf("%d%d",&total,&C)==2)
	{
		total = total>1800?total+200:total;
		dp.resize(0);
		dp.resize(total+1,0);
		for(int i=0;i<C;i++) 
		{
			scanf("%d%d",&price,&value);
			for (int i = total; i >= price; --i)
			{
				if(dp[i-price] || i == price) 
					dp[i] = max(dp[i],dp[i-price]+value);
			}
		}
//		if(a) printf("\n");
		
		if(total<2201 && total>1800)
		{
			for(int i=total-200+1;i<=2000;i++)
			{
				dp[i]=0;
			}
		}
		printf("%d\n",*max_element(dp.begin(),dp.end()));
		a=1;
	}
	return 0;
}
