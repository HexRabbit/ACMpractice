#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int a=1;
	while(1)
	{
		int temp;
		vector<int> testcase;
		testcase.resize(0);
		while(scanf("%d",&temp)==1 and temp != -1)
		{
			testcase.push_back(temp);
		}
		if(!testcase.size()) return 0;
		vector<int> maxlen;
		maxlen.resize(0);
		maxlen.resize(testcase.size(),1);
		for(int i=0; i<testcase.size(); ++i)
		{
			for(int j=0; j<i; ++j)
			{
				if(testcase[i]<=testcase[j])
				{
					maxlen[i]=max(maxlen[i],maxlen[j]+1);
				}
			}
		}
		if(a>1) printf("\n");
		printf("Test #%d:\n  maxmium possible interceptions: %d\n",a,*max_element(maxlen.begin(),maxlen.end()));
		++a;
	}

}
