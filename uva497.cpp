#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int cnt;
	cin >> cnt;
	cin.get();
	cin.get();
	int a=0;
	while(cnt--)
	{
		string temp;
		vector<int> testcase;
		testcase.resize(0);
		while(1)
		{
			getline(cin,temp);
			if(temp=="") break;
			testcase.push_back(stoi(temp));
		}
		if(!testcase.size()) return 0;
		vector<int> maxlen;
		vector<int> prev;
		maxlen.resize(0);
		prev.resize(0);
		prev.resize(testcase.size(),-1);
		maxlen.resize(testcase.size(),1);
		for(int i=0; i<testcase.size(); ++i)
		{
			for(int j=0; j<i; ++j)
			{
				if(testcase[i]>=testcase[j])
				{
					if(maxlen[j]+1>=maxlen[i])
					{
						maxlen[i]=maxlen[j]+1;
						prev[i]=j;
					}
				}
			}
		}
		if(a) printf("\n");
		printf("Max hits: %d\n",*max_element(maxlen.begin(),maxlen.end()));
		int mx=*max_element(maxlen.begin(),maxlen.end());
		int index=distance(maxlen.begin(),find(maxlen.begin(),maxlen.end(),mx));
		vector<int> stk;
		for(int i=index; i != -1; i=prev[i])
		{
			stk.push_back(testcase[i]);
		}
		while(!stk.empty())
		{
			cout << stk.back() << endl;
			stk.pop_back();
		}
		a=1;
	}

}
