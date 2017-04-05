#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
	int a=1;
	int **lcs = new int *[200];
	int *tmp = new int[40000];
	for(int i=0; i<200; ++i)
	{
		lcs[i] = &tmp[i*200];
	}
	string s1,s2;
	vector<string> v1,v2;
	string temp;
	while(cin >> temp)
	{
		v1.resize(1,",");
		v2.resize(1,"^");
		v1.push_back(temp);
		while(cin >> temp and temp != "#")
		{
			v1.push_back(temp);
		}
		while(cin >> temp and temp != "#")
		{
			v2.push_back(temp);
		}
		for(int i=0; i<200; ++i)
		{
			for(int j=0; j<200; ++j)
			{
				lcs[i][j]=0;
			}
		}
		for(int i=1; i<v1.size(); ++i)
		{
			for(int j=1; j<v2.size(); ++j)
			{
				if(v1[i]==v2[j]) lcs[i][j]=lcs[i-1][j-1]+1;
				else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		int mx=lcs[v1.size()-1][v2.size()-1];
		vector<string> sout;
		sout.resize(0);
		for(int i=v1.size()-1,j=v2.size()-1;i>0 and j>0;)
		{
			if(v1[i]==v2[j]) {sout.push_back(v1[i]);--i;--j;}
			else if(lcs[i][j]==lcs[i-1][j]) --i;
			else if(lcs[i][j]==lcs[i][j-1]) --j;
		}
		int a=0;
		while(!sout.empty())
		{
			if(a) cout << " ";
			cout << sout.back();
			sout.pop_back();
			a++;
		}
		cout << endl;
	}
	return 0;
}
