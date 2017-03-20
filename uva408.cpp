#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int step,mod,temp,a=0;
	vector<int> output;
	while(scanf("%d",&step)==1)
	{
		scanf("%d",&mod);
		temp=0;
		output.resize(0);
		for (;;)
		{
			if (output.size()>0 && temp==output.at(0)) break;
			output.push_back(temp);
			temp+=step;
			temp%=mod;
		}
//		if(a>0) printf("\n");
		if (output.size()==mod)
		{
			printf("%10d%10d    Good Choice\n\n", step,mod);
		}
		else
		{
			printf("%10d%10d    Bad Choice\n\n", step,mod);
		}
//		a++;
	}
	return 0;
}