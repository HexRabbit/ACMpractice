#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int coin[5]={1,5,10,25,50};
	vector<int> dp;
	int total;
	while(cin >> total){
		dp.resize(0);
		dp.resize(total+1,0);
		dp.at(0)=1;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = coin[i]; j <= total; ++j)
			{
				dp.at(j)+=dp.at(j-coin[i]);
			}
		}
		printf("%d\n", dp.at(total));
	}
	return 0;
}